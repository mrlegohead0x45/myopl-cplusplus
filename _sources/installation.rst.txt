------------
Installation
------------

Prerequisites
-------------

- Have `vcpkg <https://vcpkg.io/en/getting-started.html>`_ installed
- Have `CMake <https://cmake.org/install>`_ installed

Compile
-------

1. Obtain the source code for this project from the
   `releases page <https://github.com/mrlegohead0x45/myopl-cplusplus/releases>`_
   as the main branch is often a work in progress and may not even compile.
   Alternatively, if you want to help develop this project,
   see :doc:`/development`, as help is always welcome

2. Create a :code:`build` directory
   :code:`$ mkdir build; cd build`

3. Run CMake to generate build files, passing in the path to vcpkg
   :code:`$ cmake .. -DCMAKE_TOOLCHAIN_FILE=path/to/vcpkg/scripts/buildsystems/vcpkg.cmake`

4. Run those build files
   :code:`$ cmake --build .`
