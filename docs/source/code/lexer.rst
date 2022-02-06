-----
Lexer
-----

| Declared in file :code:`include/lexer.hpp`
| Implemented in file :code:`src/lexer.cpp`

These files contain stuff related to lexing input into :class:`Token`

.. struct:: LexResult

   .. member:: std::vector<Token> tokens

      A vector of :class:`Token` representing the lexed tokens.
      It will be empty if an error was returned

   .. member:: std::optional<Error> error

      A :code:`std::optional<Error>` that represents the error that was returned if there was one.
      If there wasn't it will be :code:`std::nullopt`

.. class:: Lexer

   A class that handles lexing input into :class:`Token`

   .. function:: Lexer(std::string t)

      Initialise this :class:`Lexer` with :member:`text` as :var:`t`

   .. function:: void advance()

      Advance this :class:`Lexer` by incrementing :member:`pos` and setting
      :member:`current_char` accordingly

   .. function:: Token make_number()

      Create a :class:`Token` of a number at the current position

   .. function:: LexResult make_tokens()

      Lex :member:`text` into a :struct:`LexResult` and return it

   .. member:: std::string text

      The text to lex into :class:`Token`

   .. member:: int pos = -1

      The current position of this :class:`Lexer`

   .. member:: std::optional<std::string> current_char

      The character we are currently lexing.
      It will be :code:`std::nullopt` if we reached the end of :member:`text`
