cmake_minimum_required(VERSION 3.25)
project(TCPSocket VERSION 0.1.2 DESCRIPTION "TCP Socket" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# Specify C++ Standard
set(CMAKE_CXX_STANDARD 17)

# Add the source files
set(SOURCES
        src/TCPClient.cpp
)

# Add the header files
set(HEADERS
        include/TCPSocket/TCPClient.hpp
        include/TCPSocket/TCPUtils.hpp
)

add_library(TCPSocket SHARED ${SOURCES} ${HEADERS})

set_target_properties(TCPSocket PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION_MAJOR}
        PUBLIC_HEADER "${HEADERS}"
)

target_include_directories(TCPSocket PRIVATE include)
target_include_directories(TCPSocket PRIVATE src)

include(GNUInstallDirs)

install(TARGETS TCPSocket
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/TCPSocket)

configure_file(TCPSocket.pc.in TCPSocket.pc @ONLY)

install(FILES ${CMAKE_BINARY_DIR}/TCPSocket.pc DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)