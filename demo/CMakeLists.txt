if(QMLMATERIALCOLORUTILITIES_BUILD_WITH_SANITIZE)
  set(CMAKE_CXX_FLAGS
      "${CMAKE_CXX_FLAGS} -fsanitize=address  -fsanitize=leak -g")
endif(QMLMATERIALCOLORUTILITIES_BUILD_WITH_SANITIZE)

add_subdirectory(dynamicscheme)
add_subdirectory(hcttorgb)
