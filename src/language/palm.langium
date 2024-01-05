grammar Palm

entry Program:
    Module (types+=Type | functions+=FunctionDefinition<false, false>)*;

Module:
  'module' name=ID;

Type:
  Primitive | Enum | Trait | Entity | Extension;

Primitive:
  'primitive' name=ID '{'
    (methods+=FunctionDefinition<true, false>)*
  '}';

Enum:
  'enum' name=ID  Generics '{'
      (fields+=EnumField)*
      (methods+=FunctionDefinition<true, false>)*
  '}';

EnumField:
    name=ID;

Trait:
  'trait' name=ID  Generics '{'
      (methods+=FunctionDefinition<true, true>)*
  '}';

Extension:
  'extension' name=ID 'on' type=[Entity] '{'
      (methods+=FunctionDefinition<true, false>)*
  '}';

Entity:
  'entity' name=ID  Generics '{'
      (fields+=Field)*
      (methods+=FunctionDefinition<true, false>)*
  '}';

Field:
  names+=ID ((',' names+=ID)*)? ':' type=[Type:ID];

fragment Generics:
  ('<' generics+=GENERIC_ID (',' generics+=GENERIC_ID)* '>')?;

QualifiedName returns string:
    ID ('.' ID)*;

type AbstractDefinition = FunctionDefinition | Param;

FunctionDefinition<isMethod, isTrait>: 
  (<isMethod> static?='static')? 
  'fn' name=ID '(' (params+=Param (',' params+=Param)*)? ')' ('->' returns+=ReturnType (',' returns+=ReturnType)*)? (<!isTrait> Block);

ParamType:
  type=[Type] (nilable?='?')?;

Param:
  name=ID ':' type=ParamType;

fragment Block:
  '{' body+=Stmt* '}';

ReturnType:
  type=[Type] (nilable?='?')? (throws?='!')?;

Stmt: Assignment | FnCall;

Assignment:
  'const' name=ID '=' rhs=(FnCall|STRING|INT|NUMBER);

FnCall: 
  fnName=[FunctionDefinition:ID] '(' (args+=Expression (',' args+=Expression)*)? ')';

Expression:
    Addition;

Addition infers Expression:
    Multiplication ({infer BinaryExpression.left=current} operator=('+' | '-') right=Multiplication)*;

Multiplication infers Expression:
    Exponentiation ({infer BinaryExpression.left=current} operator=('*' | '/') right=Exponentiation)*;

Exponentiation infers Expression:
    Modulo ({infer BinaryExpression.left=current} operator='^' right=Modulo)*;

Modulo infers Expression:
    PrimaryExpression ({infer BinaryExpression.left=current} operator='%' right=PrimaryExpression)*;

PrimaryExpression infers Expression:
    '(' Expression ')' |
    {infer NumberLiteral} value=NUMBER |
    {infer StringLiteral} value=STRING |
    {infer ReferenceLiteral} value=[Param:QualifiedName] ('(' args+=Expression (',' args+=Expression)* ')')?;
    // {infer FunctionCall} func=[FunctionDefinition:ID] ('(' args+=Expression (',' args+=Expression)* ')')?;

terminal ID: /[_a-zA-Z][\w_]*/;
terminal GENERIC_ID: /(a|b|c)/;
terminal VAR_ID: /[_a-z][\w_]*/;
terminal INT returns number: /[0-9]+/;
terminal STRING: /"(\\.|[^"\\])*"|'(\\.|[^'\\])*'/;
terminal HEX:    /#(\d|[a-fA-F])+/;
terminal NUMBER returns number: /[0-9]+(\.[0-9]*)?[a-z]*/;

hidden terminal WS: /\s+/;
hidden terminal ML_COMMENT: /\/\*[\s\S]*?\*\//;
hidden terminal SL_COMMENT: /\/\/[^\n\r]*/;
