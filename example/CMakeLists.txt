cmake_minimum_required(VERSION 3.25)
project(example)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig REQUIRED)
pkg_check_modules(TCPSocket REQUIRED TCPSocket)

add_executable(client client.test.cpp)

target_link_libraries(client TCPSocket)