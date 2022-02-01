git clone https://github.com/microsoft/vckpg
cd vckpg
./bootstrap-vcpkg.sh

cd ..
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build .
./myopl-cpp
