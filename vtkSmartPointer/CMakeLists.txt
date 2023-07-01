cmake_minimum_required(VERSION 3.15)
project(vtkSmartPointer)

find_package(VTK 
COMPONENTS
  CommonCore
)

add_executable(main main.cpp)
set(emscripten_optimization_flags -g3 -O0)
target_link_libraries(main PRIVATE VTK::CommonCore)
target_link_options(main PRIVATE
  "-lembind"
  "-sMODULARIZE=1"
  "-sEXPORT_NAME=loadvtkSmartPointerWasmModule"
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
