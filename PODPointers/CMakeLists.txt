cmake_minimum_required(VERSION 3.15)

project(PODPointers)


add_executable(fooWeb foo.h foo.cpp foo.embind.cpp)
set(emscripten_optimization_flags -g3 -O0)
target_link_options(fooWeb PRIVATE
  "-lembind" 
  "-sMODULARIZE=1" 
  "-sEXPORT_ES6=1" 
  "-sEXPORT_NAME=loadPODPointersWasmModule" 
  "-sEXPORTED_FUNCTIONS=['_free', '_malloc']"
  "${emscripten_optimization_flags}")
target_compile_options(fooWeb PRIVATE ${emscripten_optimization_flags})
target_compile_definitions(fooWeb PRIVATE COPY_VALUES=0)
# Copy HTML to build directory
add_custom_command(
  TARGET fooWeb
  COMMAND
    ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_CURRENT_SOURCE_DIR}/index.html"
      "${CMAKE_CURRENT_SOURCE_DIR}/index.js"
      $<TARGET_FILE_DIR:fooWeb>
)
