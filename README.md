# wasm-bits

This is a collection of concise, targeted C++/JS examples that show how to wrap a C++ feature to JavaScript with Embind.

Each directory has a single `main.cpp` file or other `.cpp` files, a `CMakeLists.txt` file which can generate the build system files and an `index.html` file which can be used to test the wasm module in a browser.

- [**Args**](https://github.com/jspanchu/wasm-bits/tree/main/Args) - Pass command line arguments to a main function.
- [**Constants**](https://github.com/jspanchu/wasm-bits/tree/main/Constants) - Wrap constants with embind.
- [**CrossModule**](https://github.com/jspanchu/wasm-bits/tree/main/CrossModule) - Doesn't work. Attempts to make call functions defined in one module with an argument from another module.
- [**DynamicLinkingClasses**](https://github.com/jspanchu/wasm-bits/tree/main/DynamicLinkingClasses) - Create two shared libraries and use classes from the libraries in `main`.
- [**DynamicLinkingGL**](https://github.com/jspanchu/wasm-bits/tree/main/DynamicLinkingGL) - Use OpenGL in shared library.
- [**DynamicLinkingSimple**](https://github.com/jspanchu/wasm-bits/tree/main/DynamicLinkingGL) - Create a shared library and call a function from the library in `main`.
- [**EmVal**](https://github.com/jspanchu/wasm-bits/tree/main/EmVal) - Shows usage of `emscripten::val` to pass any JavaScript object to C++.
- [**Enums**](https://github.com/jspanchu/wasm-bits/tree/main/Enums) - Wraps C/C++ style (un)scoped enums with embind.
- [**Env**](https://github.com/jspanchu/wasm-bits/tree/main/Env) - Shows how to populate runtime environment so that `getenv` can retrieve environment variables.
- [**FunctionPointer**](https://github.com/jspanchu/wasm-bits/tree/main/FunctionPointer) - Shows how to pass a JavaScript function to a C/C++ function that accepts a function pointer and then invoke that JavaScript function from C++.
- [**Memory64**](https://github.com/jspanchu/wasm-bits/tree/main/Memory64) - node.js example tries to use 64-bit integers and 64-bit memory.
- [**PODPointers**](https://github.com/jspanchu/wasm-bits/tree/main/PODPointers) - wraps native functions that accept and return raw pointers as a view using `emscripten::typed_memory_view`.
- [**SharedPointer**](https://github.com/jspanchu/wasm-bits/tree/main/SharedPointer) - Shows how to construct embound objects with `std::shared_ptr`.
- [**Threads**](https://github.com/jspanchu/wasm-bits/tree/main/Threads) - WIP
- [**UnityBuildMultiLibsSingleModule**](https://github.com/jspanchu/wasm-bits/tree/main/UnityBuildMultiLibsSingleModule) - Similar to CrossModule, but the bindings are built as one whole translation unit.
- [**Virtuals**](https://github.com/jspanchu/wasm-bits/tree/main/Virtuals) - Shows how to wrap (with embind) and implement C++ pure virtual classes in JavaScript
- [**vtkSmartPointer**](https://github.com/jspanchu/wasm-bits/tree/main/vtkSmartPointer) - Implements the `emscripten::smart_ptr_trait` for `vtkSmartPointer` and shows how C++ `vtkObject` instances can be automatically garbage collected from JavaScript.
- [**vtkWasmThreadedFilters**](https://github.com/jspanchu/wasm-bits/tree/main/vtkWasmThreadedFilters) - WIP
