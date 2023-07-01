cmake_minimum_required(VERSION 3.15)

project(UnityBuildMultiLibsSingleModule)

add_library(modA modA.h modA.cpp)
add_library(modB modB.h modB.cpp)

target_link_libraries(modA PRIVATE modB)

set(emscripten_optimization_flags -g3 -O0)

add_executable(modJavaScript modA.bind.cpp modB.bind.cpp)
set_source_files_properties(modA.bind.cpp modB.bind.cpp PROPERTIES UNITY_GROUP mods.bind)
set_target_properties(modJavaScript PROPERTIES UNITY_BUILD TRUE UNITY_BUILD_MODE GROUP)

target_link_libraries(modJavaScript PRIVATE modA modB)
target_link_options(modJavaScript PRIVATE 
  "-lembind"
  "-sMODULARIZE=1"
  "-sEXPORT_ES6=1"
  "-sEXPORT_NAME=loadSingleWasmModule"
  "${emscripten_optimization_flags}")
target_compile_options(modJavaScript PRIVATE ${emscripten_optimization_flags})

# Copy HTML to build directory
add_custom_command(
  TARGET modJavaScript
  COMMAND
    ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_CURRENT_SOURCE_DIR}/index.html"
      "${CMAKE_CURRENT_SOURCE_DIR}/index.js"
      $<TARGET_FILE_DIR:modJavaScript>
)
