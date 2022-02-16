set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
  CACHE STRING "Vcpkg toolchain file")

cmake_minimum_required(VERSION 3.10)
project(
    myopl-cplusplus
    DESCRIPTION "'My own programming langauge' translated into C++"
    HOMEPAGE_URL "https://mrlegohead0x45.github.io/myopl-cplusplus"
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# so we can use designated initialisers
# (e.g see lexer.cpp:81, the return in the else)
# see https://en.cppreference.com/w/cpp/language/aggregate_initialization#Designated_initializers
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(
    LOGURU_HEADER_ONLY
    "Whether to use loguru as header only"
    OFF
)

file(GLOB sources "src/*.cpp")

add_executable(myopl-cpp ${sources})
target_include_directories(myopl-cpp PRIVATE "include")

# add compile options for warnings
target_compile_options(
    myopl-cpp
    PRIVATE
    $<$<CXX_COMPILER_ID:Clang,GNU,AppleClang>:
        -Wall -Werror -Wextra>
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4>
)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(myopl-cpp PRIVATE fmt::fmt)

# if we are using loguru as header only
if(LOGURU_HEADER_ONLY)
    # find and add loguru.[ch]pp to the include path
    find_path(LOGURU_INCLUDE_DIRS "loguru/loguru.cpp")
    target_include_directories(myopl-cpp PRIVATE ${LOGURU_INCLUDE_DIRS})
    target_compile_definitions(myopl-cpp PRIVATE LOGURU_HEADER_ONLY)
else()
    # else this will add it to the include path and link the library
    find_package(loguru CONFIG REQUIRED)
    target_link_libraries(myopl-cpp PRIVATE loguru)
endif()
