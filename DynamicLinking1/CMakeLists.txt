cmake_minimum_required(VERSION 3.15)
project(DynamicLinking1 C)

set(emscripten_optimization_flags -g0 -Os)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_NINJA_FORCE_RESPONSE_FILE 1 CACHE INTERNAL "")
add_library(add_one SHARED add_one.c)
target_compile_options(add_one PRIVATE ${emscripten_optimization_flags})
target_link_options(add_one PRIVATE
  "${emscripten_optimization_flags}")

add_executable(main main.c)
target_compile_options(main PRIVATE ${emscripten_optimization_flags})
target_link_options(main PRIVATE
  "${emscripten_optimization_flags}"
  "-sSTANDALONE_WASM=1"
  "-sENVIRONMENT=node")
target_link_libraries(main PRIVATE add_one)
set_target_properties(main PROPERTIES OUTPUT_NAME "index" SUFFIX ".html")
