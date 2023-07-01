#include "modA.h"
#include "emscripten/bind.h"


EMSCRIPTEN_BINDINGS(foo_class) {
  emscripten::class_<Foo>("Foo").constructor().function(
      "SetBar", &Foo::SetBar, emscripten::allow_raw_pointers());
}
