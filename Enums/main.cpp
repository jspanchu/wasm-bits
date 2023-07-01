#include "emscripten/bind.h"
#include <emscripten.h>

class Foo {
public:
  enum Bar {
    A,
    B,
  };
  enum class Bar1 {
    A,
    B,
  };
};

EMSCRIPTEN_BINDINGS(foo_enums) {
  emscripten::enum_<Foo::Bar>("Foo_Bar")
      .value("A", Foo::Bar::A)
      .value("B", Foo::Bar::B);
  emscripten::enum_<Foo::Bar1>("Foo_Bar1")
      .value("A", Foo::Bar1::A)
      .value("B", Foo::Bar1::B);
}

EMSCRIPTEN_BINDINGS(foo_class) {
  emscripten::class_<Foo>("Foo");
}
