cmake_minimum_required(VERSION 3.15)

project(Virtuals)

add_library(foo foo.h foo.cpp)

set(emscripten_optimization_flags -g3 -O0)

add_executable(fooWeb foo.embind.cpp)
target_link_libraries(fooWeb PRIVATE foo)
target_link_options(fooWeb PRIVATE
  "-lembind"
  "-sMODULARIZE=1"
  "-sEXPORT_ES6=1"
  "-sEXPORT_NAME=loadVirtualsWasmModule"
  "${emscripten_optimization_flags}")
target_compile_options(fooWeb PRIVATE ${emscripten_optimization_flags})

# Copy HTML to build directory
add_custom_command(
  TARGET fooWeb
  COMMAND
    ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_CURRENT_SOURCE_DIR}/index.html"
      "${CMAKE_CURRENT_SOURCE_DIR}/index.js"
      $<TARGET_FILE_DIR:fooWeb>
)
