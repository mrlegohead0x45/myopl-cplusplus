cmake_minimum_required(VERSION 3.10)
project(
    myopl-cplusplus
    DESCRIPTION "'My own programming langauge' translated into C++"
    HOMEPAGE_URL "https://mrlegohead0x45.github.io/myopl-cplusplus"
)

set(CMAKE_CXX_STANDARD 17) # so we can use std::optional
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB sources "src/*.cpp")

include_directories("include")
add_executable(myopl-cpp ${sources})

find_package(fmt CONFIG REQUIRED)
target_link_libraries(myopl-cpp PRIVATE fmt::fmt)
