-----------
Development
-----------

If you want to help develop this project, great!

Get started by downloading the latest source code from the GitHub
`repository <https://github.com/mrlegohead0x45/myopl-cplusplus>`_.
You should also meet the same :ref:`prerequisites-label` as for installation

You may want to add :file:`build/vcpkg_installed/{triplet}/include` to your IDE's include search path,
as this is where installed header files will end up.
:code:`triplet` should be your vcpkg target triplet (see :ref:`triplet-label`)

If you think you have made an improvement, no matter how small, please submit your changes as a
`pull request <https://github.com/mrlegohead0x45/myopl-cplusplus/compare>`_.

Please run `clang-format <https://clang.llvm.org/docs/ClangFormat.html>`_
with :code:`--style=file` (to specify the options in :code:`.clang-format`)
on your code before you submit your pull request, however.

.. _triplet-label:

Triplets
--------

For example, on my machine with MinGW installed it is :code:`x64-mingw-dynamic`.
If you were using Visual Studio on Windows it might be :code:`x64-windows`.
