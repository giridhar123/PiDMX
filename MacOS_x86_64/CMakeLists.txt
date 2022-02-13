cmake_minimum_required(VERSION 3.16)

project(UsingPiDMXLib VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#[[
list(APPEND QML_IMPORT_PATH "/Users/davide/untitled/privateProject/QML/Views")
set(QML_IMPORT_PATH ${QML_IMPORT_PATH}
    CACHE STRING "Qt Creator 4.1 extra qml import paths"
    FORCE
)
]]

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)
find_package(Qt6 COMPONENTS Sql REQUIRED)
find_package(Qt6 COMPONENTS SerialPort REQUIRED)
find_package(Qt6 COMPONENTS QuickControls2 REQUIRED)
find_package(Qt6 COMPONENTS Core REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/libs/include)
find_library(PiDMX PiDMX "${CMAKE_SOURCE_DIR}/libs/lib")

find_library(extra_module
    libextra_module.dylib
    PATHS ${CMAKE_SOURCE_DIR}/libs/lib/)

add_executable(UsingPiDMXLib main.cpp)
target_link_libraries(UsingPiDMXLib
    PRIVATE ${PiDMX}
    PRIVATE Qt6::Quick
    PRIVATE Qt6::Sql
    PRIVATE Qt6::SerialPort
    PRIVATE Qt6::QuickControls2
    PRIVATE Qt6::Core
    PRIVATE ${extra_module})

message("AAA: ${PiDMX}")
link_directories(${CMAKE_SOURCE_DIR}/libs/lib)

target_compile_definitions(UsingPiDMXLib
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
