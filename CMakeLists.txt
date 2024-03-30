cmake_minimum_required(VERSION 3.22)

project(qmlhtc LANGUAGES C CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MATERIAL_COLOR_UTILITIES_DIR ${CMAKE_SOURCE_DIR}/material-color-utilities)

set(MATERIAL_COLOR_UTILITIES_CPP_DIR ${MATERIAL_COLOR_UTILITIES_DIR}/cpp)

set(MATERIAL_COLOR_UTILITIES_SOURCES
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/blend/blend.cc
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/cam/cam.cc
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/cam/hct_solver.cc
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/cam/hct.cc
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/cam/viewing_conditions.cc
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/contrast/contrast.cc
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/dislike/dislike.cc
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/dynamiccolor/dynamic_color.cc
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/dynamiccolor/dynamic_scheme.cc
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/dynamiccolor/material_dynamic_colors.cc
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/palettes/core.cc
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/palettes/tones.cc
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/quantize/celebi.cc
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/quantize/lab.cc
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/quantize/wsmeans.cc
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/quantize/wu.cc
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/scheme/scheme_content.cc
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/scheme/scheme_expressive.cc
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/scheme/scheme_fidelity.cc
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/scheme/scheme_fruit_salad.cc
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/scheme/scheme_monochrome.cc
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/scheme/scheme_neutral.cc
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/scheme/scheme_rainbow.cc
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/scheme/scheme_tonal_spot.cc
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/scheme/scheme_vibrant.cc
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/scheme/scheme.cc
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/score/score.cc
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/temperature/temperature_cache.cc
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/utils/utils.cc)

set(MATERIAL_COLOR_UTILITIES_HEADERS
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/blend/blend.h
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/cam/cam.h
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/cam/hct_solver.h
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/cam/hct.h
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/cam/viewing_conditions.h
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/contrast/contrast.h
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/dislike/dislike.h
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/dynamiccolor/dynamic_color.h
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/dynamiccolor/dynamic_scheme.h
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/dynamiccolor/material_dynamic_colors.h
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/palettes/core.h
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/palettes/tones.h
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/quantize/celebi.h
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/quantize/lab.h
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/quantize/wsmeans.h
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/quantize/wu.h
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/scheme/scheme_content.h
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/scheme/scheme_expressive.h
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/scheme/scheme_fidelity.h
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/scheme/scheme_fruit_salad.h
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/scheme/scheme_monochrome.h
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/scheme/scheme_neutral.h
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/scheme/scheme_rainbow.h
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/scheme/scheme_tonal_spot.h
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/scheme/scheme_vibrant.h
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/scheme/scheme.h
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/score/score.h
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/temperature/temperature_cache.h
    ${MATERIAL_COLOR_UTILITIES_CPP_DIR}/utils/utils.h)

add_library(htc ${MATERIAL_COLOR_UTILITIES_SOURCES}
                ${MATERIAL_COLOR_UTILITIES_HEADERS})

target_include_directories(htc PUBLIC ${MATERIAL_COLOR_UTILITIES_DIR})

set(QT_VERSION_MAJOR 6)

find_package(
  Qt${QT_VERSION_MAJOR}
  COMPONENTS Core Quick
  REQUIRED)

set(Qt_LIBS Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick)

add_executable(qmlhtc main.cpp qml.qrc)

target_link_libraries(qmlhtc PUBLIC htc absl_strings ${Qt_LIBS})
