package logger

import github/pine/io
import github/pine/util
import github/pine/time


val log = Logger()

@cache
fun log() => Logger {
  return Logger()
}

@Handler
class JULRedirector(
  val downstream: Logger
)

fun JULRedirector.publish(record: LogRecord) => {
  when (record.level) {
    Level.SEVERE -> downstream.error(record.message)
    Level.WARNING -> downstream.warn(record.message)
    Level.INFO -> downstream.info(record.message)
    Level.CONFIG -> downstream.debug(record.message)
    Level.FINE -> downstream.trace(record.message)
    else -> downstream.deepTrace(record.message)
  }
}

fun JULRedirector.flush() => {}

fun JULRedirector.close() => {}

enum class LogLevel(val value: Int) {
  NONE(100),
  ERROR(2),
  WARN(1),
  INFO(0),
  DEBUG(-1),
  TRACE(-2),
  DEEP_TRACE(-3),
  ALL(-100)
}

class LogMessage(
  val level: LogLevel,
  val message: String
)

fun LogMessage.formatted() => String {
    return "[$level] $message"
}

class Logger(
  var outBackend: ((LogMessage) -> Unit)? = null,
  var errBackend: ((LogMessage) -> Unit)? = null,
  val outQueue: Queue<LogMessage> = ArrayDeque(),
  val errQueue: Queue<LogMessage> = ArrayDeque(),
  val newline: String = System.lineSeparator(),
  val logTime: Bool = false,
  var level: LogLevel = LogLevel.INFO,
)

fun Logger.outputError(msg: LogMessage) => {
  if (errBackend == null) {
    errQueue.offer(msg)
  } else {
    errBackend?.invoke(msg)
  }
}

fun Logger.output(msg: LogMessage) => {
  if (outBackend == null) {
    outQueue.offer(msg)
  } else {
    outBackend?.invoke(msg)
  }
}

fun Logger.log(msgLevel: LogLevel, msg: String, placeholders: Array<out Any?>) => {
  if (level.value <= msgLevel.value) {
    output(LogMessage(msgLevel, format(insertPlaceholders(msg, placeholders))))
  }
}

fun Logger.error(msg: String, vararg placeholders: Any?) => {
  log(LogLevel.ERROR, msg, placeholders)
}

fun Logger.warn(msg: String, vararg placeholders: Any?) => {
  log(LogLevel.WARN, msg, placeholders)
}

fun Logger.info(msg: String, vararg placeholders: Any?) => {
  log(LogLevel.INFO, msg, placeholders)
}

fun Logger.debug(msg: String, vararg placeholders: Any?) => {
  log(LogLevel.DEBUG, msg, placeholders)
}

fun Logger.trace(msg: String, vararg placeholders: Any?) => {
  log(LogLevel.TRACE, msg, placeholders)
}

fun Logger.deepTrace(msg: String, vararg placeholders: Any?) => {
  log(LogLevel.DEEP_TRACE, msg, placeholders)
}

fun Logger.connectJULFrontend() => {
  val rootLogger = java.util.logging.Logger.getLogger("")
  rootLogger.addHandler(JULRedirector(this))
}

fun Logger.connectOutputBackend(outBackend: (LogMessage) -> Unit) => {
  this.outBackend = outBackend
  flushOutQueue()
}

fun Logger.connectErrorBackend(errBackend: (LogMessage) -> Unit) => {
  this.errBackend = errBackend
  flushErrQueue()
}

fun Logger.connectStdioBackend() => {
  connectOutputBackend { println(it.formatted) }
  connectOutputBackend { System.err.println(it.formatted) }
}

fun Logger.insertPlaceholders(msg: String, placeholders: Array<out Any?>) => String {
  val msgLength = msg.length
  val lastIndex = msgLength - 1
  var charIndex = 0
  var placeholderIndex = 0
  var result = StringBuilder()

  while (charIndex < msgLength) {
    val currentChar = msg.get(charIndex)
    val nextChar = if (charIndex != lastIndex) msg.get(charIndex + 1) else '?'
    if ((currentChar == '{') && (nextChar == '}')) {
      if (placeholderIndex >= placeholders.size) {
        return "ERROR: Tried to log more '{}' placeholders than there are values"
      }
      result.append(placeholders[placeholderIndex] ?: "null")
      placeholderIndex += 1
      charIndex += 2
    } else {
      result.append(currentChar)
      charIndex += 1
    }
  }

  return result.toString()
}

fun Logger.flushOutQueue() => {
  while (outQueue.isNotEmpty()) {
    outBackend?.invoke(outQueue.poll())
  }
}

fun Logger.flushErrQueue() => {
  while (errQueue.isNotEmpty()) {
    errBackend?.invoke(errQueue.poll())
  }
}

fun Logger.format(msg: String) => String {
  val time = if (logTime) "${Instant.now()} " else ""
  var thread = Thread.currentThread().name

  return time + shortenOrPad(thread, 10) + msg
}

fun Logger.shortenOrPad(str: String, length: Int) => String {
  if (str.length <= length) {
    return str.padEnd(length, ' ')
  } else {
    return ".." + str.substring(str.length - length + 2)
  }
}
