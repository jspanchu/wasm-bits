#include "foo.h"
#include "emscripten/bind.h"

class FooWrapper : public emscripten::wrapper<Foo> {
public:
  EMSCRIPTEN_WRAPPER(FooWrapper);
  std::string GetClassName() { return call<std::string>("GetClassName"); }
  std::string GetClassNameImplementation() {
    return call<std::string>("GetClassNameImplementation");
  }
};

EMSCRIPTEN_BINDINGS(foo_class) {
  emscripten::class_<Foo>("Foo")
      .allow_subclass<FooWrapper>("FooWrapper")
      .function("GetClassNameImplementation", &Foo::GetClassNameImplementation,
                emscripten::pure_virtual())
      .function("GetClassName", emscripten::optional_override([](Foo &self) {
                  return self.Foo::GetClassName();
                }));
}
