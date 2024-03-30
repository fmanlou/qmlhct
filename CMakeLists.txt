cmake_minimum_required(VERSION 3.22)

project(qmlhtc LANGUAGES C CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(material_color_utilities.cmake)

set(QT_VERSION_MAJOR 6)

find_package(
  Qt${QT_VERSION_MAJOR}
  COMPONENTS Core Quick
  REQUIRED)

set(Qt_LIBS Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick)

add_executable(qmlhtc main.cpp qml.qrc)

target_link_libraries(qmlhtc PUBLIC htc ${Qt_LIBS})
