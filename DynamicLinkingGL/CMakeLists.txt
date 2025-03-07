cmake_minimum_required(VERSION 3.15)

project(CrossModuleEmbind)

set(emscripten_optimization_flags -g3 -O0)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# set(CMAKE_NINJA_FORCE_RESPONSE_FILE 1 CACHE INTERNAL "")

add_library(Renderer SHARED Renderer.h Renderer.cpp)
target_compile_options(Renderer PRIVATE ${emscripten_optimization_flags})
target_link_options(Renderer PRIVATE "${emscripten_optimization_flags}")

add_library(GLRenderer SHARED GLRenderer.h GLRenderer.cpp)
target_compile_options(GLRenderer PRIVATE ${emscripten_optimization_flags})
target_link_options(GLRenderer PRIVATE "${emscripten_optimization_flags}")
target_link_libraries(GLRenderer PUBLIC Renderer)

add_executable(main main.cpp)
target_include_directories(main PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_link_options(main PRIVATE "-sMAX_WEBGL_VERSION=2" "${emscripten_optimization_flags}")
target_compile_options(main PRIVATE ${emscripten_optimization_flags})
target_link_libraries(main PRIVATE GLRenderer)
# DOES NOT WORK without target_link_directories!
# C:\WINDOWS\system32\cmd.exe /C "cd . && C:\Users\jaswant.panchumarti\dev\emsdk\upstream\emscripten\em++.bat  -sMAIN_MODULE=1   -g3 -O0 CMakeFiles/main.dir/main.cpp.o -o index.html  libfoo.wasm  libbar.wasm && cd ."
# em++: error: libfoo.wasm: shared library dependency not found in library path: `libbar.wasm`. (library path: ['C:\\Users\\jaswant.panchumarti\\dev\\emsdk\\upstream\\emscripten\\cache\\sysroot\\lib\\wasm32-emscripten\\pic', 'C:\\Users\\jaswant.panchumarti\\dev\\emsdk\\upstream\\emscripten\\src\\lib']
# ninja: build stopped: subcommand failed.
target_link_directories(main PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
set_target_properties(main PROPERTIES OUTPUT_NAME "index" SUFFIX ".html")
