cmake_minimum_required(VERSION 3.14)
project(FibonacciHTTP2Uploader VERSION 0.1)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BUILD_CPR_TESTS OFF)
set(CMAKE_USE_OPENSSL OFF)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(src)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/whoshuu/cpr.git GIT_TAG c8d33915dbd88ad6c92b258869b03aba06587ff9)
FetchContent_MakeAvailable(cpr)

find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONCPP jsoncpp)