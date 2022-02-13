-----------
Contribute
-----------

If you want to contribute to this project, great!
We would really appreciate your contribution

Contributing
------------

Get started by creating a fork of the GitHub
`repository <https://github.com/mrlegohead0x45/myopl-cplusplus>`_
and cloning it locally, preferably with the :code:`--recurse-submodules` flag
to download vcpkg, which enables you to skip the :code:`git submodule` commands lower down.

Advice
~~~~~~

You may want to add :file:`build/vcpkg_installed/{triplet}/include` and :code:`include` 
to your IDE's include search path,
as this is where installed header files and our headers are respectively.
:code:`triplet` should be your vcpkg target triplet (see :ref:`triplet-label`).
Or you could just look.

For example in my :code:`.vscode/c_cpp_properties.json` I have

.. code-block:: javascript

   {
       "configurations": [
           {
                ...
               "includePath": [
                   "${default}",
                   "${workspaceFolder}/include",
                   "${workspaceFolder}/build/vcpkg_installed/x64-mingw-dynamic/include"
               ]
               ...
           }
       ]
   }


Submitting your changes
~~~~~~~~~~~~~~~~~~~~~~~

If you think you have made an improvement, no matter how small, please submit your changes as a
`pull request <https://github.com/mrlegohead0x45/myopl-cplusplus/compare>`_.

Please run `clang-format <https://clang.llvm.org/docs/ClangFormat.html>`_
on your code before you submit your pull request, like so :file:`$ clang-format -i --style=file {changed files}`.
Please also make sure your code compiles, following the :ref:`compiling-label` instructions.

.. _compiling-label:

Compiling
---------

Prerequisites
~~~~~~~~~~~~~

#. Have `CMake <https://cmake.org>`_
#. Have `Git <https://git-scm.com>`_
#. Have a C++ compiler

Any text that starts with a :code:`$` should be run from the command line
(without the :code:`$`)

vcpkg
~~~~~

You will need to run :code:`$ git submodule init` and :code:`$ git submodule update`
in order to download vcpkg. Then run :code:`$ ./vcpkg/bootstrap-vcpkg.sh`
(or :code:`$ .\vcpkg\bootstrap-vcpkg.bat` on Windows) to set it up.

Compiling
~~~~~~~~~

| Run CMake to generate build files (known as configuring),
  specifying :file:`-DVCPKG_TARGET_TRIPLET={triplet}`
  if necessary (see :ref:`triplet-label`)
  and :file:`-G {generator}` as well if necessary (see 
  `CMake generators <https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html>`_)
| :code:`$ cmake -B build -S .`

| Then you can run those build files to actually compile the code
| :code:`$ cmake --build build`
| You might want to pass the :file:`-j {jobs}` flag to speed up the build
  by running multiple processes. To find a suitable value, on Linux you can run :code:`$ nproc`
  in a terminal. On Windows, you can go to
  Start > Task Manager > More details > Performance > CPU > Logical processors.

.. _triplet-label:

Triplets
--------

If you are cross-compiling (compiling with a compiler that is not native to your system),
you may need to specify the target triplet.
For example, on my machine with MinGW installed I need to pass
:code:`-DVCPKG_TARGET_TRIPLET=x64-mingw-dynamic` to CMake which tells vcpkg to build the
dependencies for use with MinGW.

Docs
----

If your changes include modifying the documentation, you will want to build the docs
to check that they do actually build and that the build looks how you intended it to.
To do this you will need `Python <https://python.org>`_ and `Sphinx <https://www.sphinx-doc.org>`_.
To build the docs, :code:`cd` to the :code:`docs` directory and on Windows run
:code:`$ .\make.bat html` and on \*nix run :code:`$ make html`, which will build the docs and place
them in :code:`docs/build/html` with :code:`index.html` as the homepage.
