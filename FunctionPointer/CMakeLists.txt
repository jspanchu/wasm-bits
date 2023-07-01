cmake_minimum_required(VERSION 3.15)
project(FunctionPointer)

add_executable(main main.cpp)
set(emscripten_optimization_flags -g3 -O0)
target_link_options(main PRIVATE
  "-lembind"
  "-sMODULARIZE=1"
  "-sEXPORT_NAME=loadFunctionPointerWasmModule"
  # "-sDEFAULT_LIBRARY_FUNCS_TO_INCLUDE='\"\$addFunction\"'" # https://gitlab.kitware.com/cmake/cmake/-/issues/25049
  "-sINCLUDE_FULL_LIBRARY=1"
  "-sEXPORTED_RUNTIME_METHODS='\"addFunction\"'"
  "-sALLOW_TABLE_GROWTH=1"
  "${emscripten_optimization_flags}")
target_compile_options(main PRIVATE ${emscripten_optimization_flags})

# Copy HTML to build directory
add_custom_command(
  TARGET main
  COMMAND
    ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_CURRENT_SOURCE_DIR}/index.html"
      $<TARGET_FILE_DIR:main>
)
