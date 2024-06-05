cmake_minimum_required(VERSION 3.20)

set(PROJECT_NAME "lilDevil")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(${PROJECT_NAME} LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

find_package(spdlog REQUIRED)
find_package(Qt5 COMPONENTS Gui Concurrent Widgets Network REQUIRED)


set(RESOURCE_FILES ${PROJECT_NAME}.qrc)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


file(GLOB H_FILES "src/*.h")
file(GLOB CPP_FILES "src/*.cpp")
add_executable(${PROJECT_NAME} ${CPP_FILES} ${H_FILES} ${RESOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets Qt5::Network Qt5::Concurrent Qt5::Gui)