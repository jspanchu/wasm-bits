cmake_minimum_required(VERSION 3.15)

project(CrossModuleEmbind)

add_library(modA modA.h modA.cpp)
add_library(modB modB.h modB.cpp)

target_link_libraries(modA PRIVATE modB)

set(emscripten_optimization_flags -g3 -O0)

add_executable(modAJavaScript modA.bind.cpp)
add_executable(modBJavaScript modB.bind.cpp)

target_link_libraries(modAJavaScript PRIVATE modA modB)
target_link_options(modAJavaScript PRIVATE 
  "-lembind"
  "-sWASM=1"
  "-sMODULARIZE=1"
  "-sEXPORT_ES6=1"
  "-sEXPORT_NAME=loadWasmModuleA"
  "${emscripten_optimization_flags}")
target_compile_options(modAJavaScript PRIVATE ${emscripten_optimization_flags})

target_link_libraries(modBJavaScript PRIVATE modB)
target_link_options(modBJavaScript PRIVATE 
  "-lembind"
  "-sWASM=1"
  "-sMODULARIZE=1"
  "-sEXPORT_ES6=1"
  "-sEXPORT_NAME=loadWasmModuleB"
  "${emscripten_optimization_flags}")
target_compile_options(modBJavaScript PRIVATE ${emscripten_optimization_flags})

# Copy HTML to build directory
add_custom_command(
  TARGET modAJavaScript
  COMMAND
    ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_CURRENT_SOURCE_DIR}/index.html"
      "${CMAKE_CURRENT_SOURCE_DIR}/index.js"
      $<TARGET_FILE_DIR:modAJavaScript>
)
