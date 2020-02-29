cmake_minimum_required(VERSION 3.1.0)

set(CMAKE_CONFIGURATION_TYPES "Debug;MinSizeRel" CACHE STRING "" FORCE)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(QtCommon)

project(lilDevil)

set(COMPANY "Twelve Chairs Software, LLC")
set(COPYRIGHT "Copyright (c) 2020 Twelve Chairs Software, LLC. All rights reserved.")
set(IDENTIFIER "com.twelvechairs-software.lildevil")
set(LICENSE "MIT")

if (APPLE)
    set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/dist/homebrew)
    set(CMAKE_PREFIX_PATH "/usr/local/opt/qt")

elseif (WIN32)
    set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/dist/choco)
    set(WIN32QT "C:/Qt/5.13.1/msvc2017")
    set(CMAKE_PREFIX_PATH ${WIN32QT})
    set(DLLLIST "Widgets;Concurrent;Gui;Network")
    foreach(DLL ${DLLLIST})
        file(COPY ${WIN32QT}/bin/Qt5${DLL}d.dll
                DESTINATION ${CMAKE_BINARY_DIR})
        file(COPY ${WIN32QT}/bin/Qt5${DLL}.dll
                DESTINATION ${CMAKE_BINARY_DIR})
    endforeach()

else()
    set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/dist/snap)
    set(CMAKE_PREFIX_PATH "/usr/local/opt/qt")


endif()

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

find_package(Qt5Widgets REQUIRED)

add_project_meta(META_FILES_TO_INCLUDE)
set(RESOURCE_FILES ${PROJECT_NAME}.qrc)

add_executable(${PROJECT_NAME}
        ${OS_BUNDLE}
        src/main.cpp
        src/main.h
        src/mainwindow.cpp
        src/mainwindow.h
        src/configdialog.cpp
        src/configdialog.h
        src/jiratab.cpp
        src/jiratab.h
        src/confluencetab.cpp
        src/confluencetab.h
        src/jiraissue.cpp
        src/jiraissue.h
        src/githubtab.cpp
        src/githubtab.h
        src/jenkinstab.cpp
        src/jenkinstab.h
        ${META_FILES_TO_INCLUDE}
        ${RESOURCE_FILES}
        )

qt5_use_modules(${PROJECT_NAME} Gui Concurrent Widgets Network)