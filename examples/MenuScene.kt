@Scene
class MenuScene(
  name: string
)

fun MenuScene.init() {
    log("Hello world")
    log("new data")
    showToast("Toasting", 2)
}

fun MenuScene.onClick(scene: Scene, actor: Actor) {
    val nextScene = when (actor.name) {
        "Play" -> GameScene,
        "Play3d" -> Game3dScene,
        "Options" -> OptionsScene,
        "Exit" -> {
            showMessageDialog(title = "Exit", message = "Are you sure you want \n to quit?")
            exit(0)
        } 
    }
    nextScene?.run {
      scene.setScene(it)
    }
}