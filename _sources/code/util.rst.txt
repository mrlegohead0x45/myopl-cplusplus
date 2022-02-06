---------
Utilities
---------

| Declared in file :code:`include/util.hpp`
| Implemented in file :code:`src/util.cpp`

These files contain useful functions that might be used anywhere

.. function:: template <typename T> bool elem_in_vec(T elem, std::vector<T> vec)

   Return :code:`true` if :var:`elem` is contained in :var:`vec`,
   :code:`false` otherwise, using :code:`std::find`

.. function:: bool is_digit_or_dot(std::string c)

   Return true if :var:`c` is an Arabic numeral 0-9 or a dot (:code:`"."`).
   This function calls the below function which does the actual comparison.

.. function:: bool is_digit_or_dot(int c)
