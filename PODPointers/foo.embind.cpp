#include "foo.h"
#include "emscripten/bind.h"
#include <cstdint>
#include <iostream>

#if COPY_VALUES
EMSCRIPTEN_BINDINGS(foo_class) {
  emscripten::class_<Foo>("Foo")
      .constructor()
      .function("setArray",
                emscripten::select_overload<void(Foo &, emscripten::val, int)>(
                    [](Foo &self, emscripten::val v, int n) {
                      if (v.isArray()) {
                        auto vec =
                            emscripten::convertJSArrayToNumberVector<int>(v);
                        self.setArray(vec.data(), n);
                      } else {
                        std::cerr << "Invalid type!" << std::endl;
                      }
                    }))
      .function("setArray",
                emscripten::select_overload<void(Foo &, emscripten::val v)>(
                    [](Foo &self, emscripten::val v) {
                      if (v.isArray()) {
                        auto vec =
                            emscripten::convertJSArrayToNumberVector<int>(v);
                        self.setArray(vec.data());
                      } else {
                        std::cerr << "Invalid type!" << std::endl;
                      }
                    }),
                emscripten::allow_raw_pointers())
      .function("getArray", emscripten::optional_override([](Foo &self) {
                  return emscripten::val(emscripten::typed_memory_view(
                      self.getNumberOfElements(), self.getArray()));
                }));
}
#else
EMSCRIPTEN_BINDINGS(foo_class) {
  emscripten::class_<Foo>("Foo")
      .constructor()
      .function("setArray",
                emscripten::select_overload<void(Foo &, uintptr_t, int)>(
                    [](Foo &self, uintptr_t v, int n) {
                      self.setArray(reinterpret_cast<int*>(v * sizeof(int)), n);
                    }))
      .function("setArray",
                emscripten::select_overload<void(Foo &, uintptr_t v)>(
                    [](Foo &self, uintptr_t v) {
                      self.setArray(reinterpret_cast<int*>(v * sizeof(int)));
                    }),
                emscripten::allow_raw_pointers())
      .function("getArray", emscripten::optional_override([](Foo &self) {
                  return emscripten::val(emscripten::typed_memory_view(
                      self.getNumberOfElements(), self.getArray()));
                }))
      .function("setArray3D",
                emscripten::select_overload<void(Foo &, uintptr_t v)>(
                    [](Foo &self, uintptr_t v) {
                      self.setArray3D(reinterpret_cast<int(*)[3][4]>(v * sizeof(int)));
                    }),
                emscripten::allow_raw_pointers())
      .function("getArray3D", emscripten::optional_override([](Foo &self) {
                  return emscripten::val(emscripten::typed_memory_view(
                      2 * 3 * 4, self.getArray3D()));
                }));
}
#endif
