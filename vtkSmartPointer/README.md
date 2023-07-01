This example proves that VTK C++ objects can be exposed to javascript land such that the VTK C++ destructors are invoked when the javascript handle gets GC'd. This feature depends on [FinalizationRegistry](https://caniuse.com/mdn-javascript_builtins_finalizationregistry) spec available in all major browsers and JS runtimes.

Sample console log:
```
2023-06-16 10:38:28.122 (   0.001s) [           16C58]               main.cpp:47    INFO| Constructed vtkCustomObject (0x1a7e0)
RefCounts JS=1,CPP=1
RefCounts JS=2,CPP=1
RefCounts JS=3,CPP=1
RefCounts JS=3,CPP=1
RefCounts JS=3,CPP=1
2023-06-16 10:38:35.835 (   7.714s) [           16C58]               main.cpp:49    INFO| Destroyed vtkCustomObject (0x1a7e0)
```

As observed, the C++ reference count stays the same in JavaScript land irrelevant of how many clones occur. References made in JS continue to keep the C++ object alive. The C++ reference count will only decrement by 1 when the JS reference count goes to 0. This is possible because of the `vtkSmartPointer` specialization of emscripten's `smart_ptr_trait` template. 

Since the GC periodically checks for unused instances, it may take a while to see the destructor call in your browser.
