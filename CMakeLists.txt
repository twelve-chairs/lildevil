cmake_minimum_required(VERSION 3.20)

set(PROJECT_NAME "lilDevil")
project(${PROJECT_NAME} LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

#add_definitions("-std=c++11")

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.16.1/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake"
            EXPECTED_HASH SHA256=396e16d0f5eabdc6a14afddbcfff62a54a7ee75c6da23f32f7a31bc85db23484
            TLS_VERIFY ON)
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_configure(REQUIRES spdlog/1.9.2
        qt/5.15.2
        GENERATORS cmake cmake_paths cmake_find_package)

conan_cmake_autodetect(settings)

conan_cmake_install(PATH_OR_REFERENCE .
        BUILD missing
        REMOTE conancenter
        SETTINGS ${settings})

find_package(spdlog REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Gui Concurrent Widgets Network REQUIRED)
set(RESOURCE_FILES ${PROJECT_NAME}.qrc)

file(GLOB H_FILES "src/*.h")
file(GLOB CPP_FILES "src/*.cpp")
add_executable(${PROJECT_NAME} ${CPP_FILES} ${H_FILES} ${RESOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Widgets Qt5::Network Qt5::Concurrent Qt5::Gui)
