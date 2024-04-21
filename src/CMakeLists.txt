set(TARGET qmlmaterialcolorutilities)

set(TARGET_PUBLIC_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_library(${TARGET} ${SOURCES} ${HEADERS})

target_link_libraries(${TARGET} PUBLIC htc ${Qt_LIBS})

target_include_directories(${TARGET} PUBLIC ${TARGET_PUBLIC_INCLUDE_DIR})
