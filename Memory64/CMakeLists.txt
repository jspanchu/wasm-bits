cmake_minimum_required(VERSION 3.13)
project(Memory64)

find_package(Threads REQUIRED)
set(WASM_MEMORY_SUPPORT_TYPE "WASM64" CACHE STRING "Target wasm architecture type")
set_property(CACHE WASM_MEMORY_SUPPORT_TYPE PROPERTY
  STRINGS
    WASM32
    WASM64
    WASM32_64
)

add_executable(main main.cxx)

if (WASM_MEMORY_SUPPORT_TYPE STREQUAL "WASM32")
  target_compile_options(main PRIVATE "SHELL:-s MEMORY64=0")
  target_link_options(main PRIVATE "SHELL:-s MEMORY64=0")
elseif (WASM_MEMORY_SUPPORT_TYPE STREQUAL "WASM64")
  target_compile_options(main PRIVATE "SHELL:-s MEMORY64=1")
  target_link_options(main PRIVATE "SHELL:-s MEMORY64=1")
  target_link_options(main PRIVATE "SHELL:-s WASM_BIGINT=1")
elseif (WASM_MEMORY_SUPPORT_TYPE STREQUAL "WASM32_64")
  target_compile_options(main PRIVATE "SHELL:-s MEMORY64=2")
  target_link_options(main PRIVATE "SHELL:-s MEMORY64=2")
  target_link_options(main PRIVATE "SHELL:-s WASM_BIGINT=1")
endif()

target_compile_options(main PRIVATE "-O0;-g3")
target_link_options(main PRIVATE 
  "SHELL:-s WASM=1"
  "SHELL:-s ALLOW_MEMORY_GROWTH=1"
  "SHELL:-s MAXIMUM_MEMORY=4GB")