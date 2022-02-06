-----
Error
-----

| Declared in file :code:`include/error.hpp`
| Implemented in file :code:`src/error.cpp`

These files contain stuff related to errors encountered during lexing

.. class:: Error

   .. function:: Error(std::string n, std::string d)

      Initialise this :class:`Error` with :member:`name` as :var:`n`
      and :member:`details` as :var:`d`

   .. function:: virtual std::string as_string() const

      Return a representation of this :class:`Error` as a :code:`std::string`

   .. member:: std::string name

      The name of this :class:`Error`

   .. member:: std::string details

      The details of this :class:`Error`

.. class:: IllegalCharError: public Error

   .. function:: IllegalCharError(std::string details)

      Initialise this :class:`IllegalCharError` to have :member:`name` as
      :code:`"Illegal Character"` and :member:`details` as :var:`details`
