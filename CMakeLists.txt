cmake_minimum_required(VERSION 3.10)
project(
    myopl-cplusplus
    DESCRIPTION "'My own programming langauge' translated into C++"
    HOMEPAGE_URL "https://mrlegohead0x45.github.io/myopl-cplusplus"
)

# so we can use designated initialisers
# (e.g see lexer.cpp:81, the return in the else)
# see https://en.cppreference.com/w/cpp/language/aggregate_initialization#Designated_initializers
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

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
