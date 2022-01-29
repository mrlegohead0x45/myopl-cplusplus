Installation
------------

1. Install `vcpkg <https://vcpkg.io/en/getting-started.html>``
2. Obtain the source code for this project from the `releases page <https://github.com/mrlegohead0x45/myopl-cplusplus/releases>`
    as the main branch is often a work in progress and may not even compile
3. Create a `build` directory: `$ mkdir build; cd build`
4. Run CMake to generate build files: `$ cmake .. -DCMAKE_TOOLCHAIN_FILE=path/to/vcpkg/scripts/buildsystems/vcpkg.cmake`
5. Run those build files: `$ cmake --build .`
