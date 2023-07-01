# wasm-bits

This is a collection of concise, targeted C++/JS examples that show how to wrap a C++ feature to JavaScript with Embind.

Each directory has a single `main.cpp` file or other `.cpp` files, a `CMakeLists.txt` file which can generate the build system files and an `index.html` file which can be used to test the wasm module in a browser.

1. [**Args**](https://github.com/jspanchu/wasm-bits/tree/main/Args) - Pass command line arguments to a main function.
2. [**Constants**](https://github.com/jspanchu/wasm-bits/tree/main/Constants) - Wrap constants with embind.
3. [**CrossModule**](https://github.com/jspanchu/wasm-bits/tree/main/CrossModule) - Doesn't work. Attempts to make call functions defined in one module with an argument from another module.
4. [**EmVal**](https://github.com/jspanchu/wasm-bits/tree/main/EmVal) - Shows usage of `emscripten::val` to pass any JavaScript object to C++.
5. [**Enums**](https://github.com/jspanchu/wasm-bits/tree/main/Enums) - Wraps C/C++ style (un)scoped enums with embind.
6. [**Env**](https://github.com/jspanchu/wasm-bits/tree/main/Env) - Shows how to populate runtime environment so that `getenv` can retrieve environment variables.
7. [**FunctionPointer**](https://github.com/jspanchu/wasm-bits/tree/main/FunctionPointer) - Shows how to pass a JavaScript function to a C/C++ function that accepts a function pointer and then invoke that JavaScript function from C++.
8. [**Memory64**](https://github.com/jspanchu/wasm-bits/tree/main/Memory64) - node.js example tries to use 64-bit integers and 64-bit memory.
9. [**PODPointers**](https://github.com/jspanchu/wasm-bits/tree/main/PODPointers) - wraps native functions that accept and return raw pointers as a view using `emscripten::typed_memory_view`.
10. [**SharedPointer**](https://github.com/jspanchu/wasm-bits/tree/main/SharedPointer) - Shows how to construct embound objects with `std::shared_ptr`.
11. [**Threads**](https://github.com/jspanchu/wasm-bits/tree/main/Threads) - WIP
12. [**UnityBuildMultiLibsSingleModule**](https://github.com/jspanchu/wasm-bits/tree/main/UnityBuildMultiLibsSingleModule) - Similar to CrossModule, but the bindings are built as one whole translation unit.
13. [**Virtuals**](https://github.com/jspanchu/wasm-bits/tree/main/Virtuals) - Shows how to wrap (with embind) and implement C++ pure virtual classes in JavaScript
14. [**vtkSmartPointer**](https://github.com/jspanchu/wasm-bits/tree/main/vtkSmartPointer) - Implements the `emscripten::smart_ptr_trait` for `vtkSmartPointer` and shows how C++ `vtkObject` instances can be automatically garbage collected from JavaScript.
15. [**vtkWasmThreadedFilters**](https://github.com/jspanchu/wasm-bits/tree/main/vtkWasmThreadedFilters) - WIP
