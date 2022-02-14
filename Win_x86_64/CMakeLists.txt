cmake_minimum_required(VERSION 3.16)

project(UsingPiDMXLib VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
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
find_package(Qt6 COMPONENTS Gui REQUIRED)

find_library(PiDMX PiDMXLib "${CMAKE_SOURCE_DIR}/libs/lib/PiDMXLib")
find_library(Extra extra_module "${CMAKE_SOURCE_DIR}/libs/lib/extra_module")
find_library(Extra_ModulePlugin extra_moduleplugin "${CMAKE_SOURCE_DIR}/libs/lib/extra_moduleplugin")

add_executable(UsingPiDMXLib
    main.cpp
    ${CMAKE_SOURCE_DIR}/libs/lib/extra_moduleplugin/extra_module_qmltyperegistrations.cpp
    ${CMAKE_SOURCE_DIR}/libs/lib/extra_module/qrc_qmake_ExtraModule.cpp
    ${CMAKE_SOURCE_DIR}/libs/lib/extra_module/qrc_extra_module_raw_qml_0.cpp
    ${CMAKE_SOURCE_DIR}/libs/lib/qrc_myresources.cpp
    )
#[[
target_include_directories(UsingPiDMXLib
  PUBLIC
    ${CMAKE_SOURCE_DIR}/libs/include
)
]]
#include_directories(libs/include)

#here
#link_directories(libs/lib)

target_link_libraries(UsingPiDMXLib
    PUBLIC ${PiDMX}
    PUBLIC ${Extra}
    PUBLIC ${Extra_ModulePlugin}
    PRIVATE Qt6::Quick
    PRIVATE Qt6::Sql
    PRIVATE Qt6::SerialPort
    PRIVATE Qt6::QuickControls2
    PRIVATE Qt6::Core
    Qt6::Gui)

add_definitions(-DQT_STATICPLUGIN)

message("AAA ${PiDMX}")
message("AAA ${Extra}")
message("AAA ${Extra_ModulePlugin}")

target_compile_definitions(UsingPiDMXLib
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
