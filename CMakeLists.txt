cmake_minimum_required(VERSION 3.15.0 FATAL_ERROR)
project(QtQGen)

find_package(Qsp REQUIRED)
find_package(Qt5 5.11 REQUIRED COMPONENTS Core Network Widgets Xml)

set(CMAKE_INCLUDE_CURRENT_DIR True)

add_subdirectory(src)
