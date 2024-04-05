set(TARGET dynamicscheme)

add_executable(${TARGET} main.cpp qml.qrc)

target_link_libraries(${TARGET} PUBLIC ${Qt_LIBS} qmlmaterialcolorutilities)
