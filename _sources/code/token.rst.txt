-----
Token
-----

| Declared in file :code:`include/token.hpp`
| Implemented in file :code:`src/token.cpp`

.. class:: Token

   .. function:: Token(TokenType t)

      Initialise an empty token with type :code:`t`

   .. function:: Token(TokenType t, int i)

      Initialise a token with :member:`type` t and :member:`int_value` i

   .. function:: Token(TokenType t, double d)

      Initialise a token with :member:`type` t and :member:`double_value` d

   .. function:: std::string as_string() const

      Return a representation of this :class:`Token` as a :code:`std::string`

   .. member:: TokenType type

      The type of the token

   .. member:: std::optional<int> int_value

      The value of the token as an :code:`int` if there is one

   .. member:: std::optional<double> double_value

      The value of the token as a :code:`double` if there is one

.. enum:: TokenType : char

   .. enumerator:: TT_INT    = 'I'
   .. enumerator:: TT_FLOAT  = 'F'
   .. enumerator:: TT_PLUS   = '+'
   .. enumerator:: TT_MINUS  = '-'
   .. enumerator:: TT_MUL    = '*'
   .. enumerator:: TT_RPAREN = '('
   .. enumerator:: TT_DIV    = '/'
   .. enumerator:: TT_LPAREN = ')'


.. function:: std::string token_type_as_string(TokenType type)

   Convert a :enum:`TokenType` to :code:`std::string`
