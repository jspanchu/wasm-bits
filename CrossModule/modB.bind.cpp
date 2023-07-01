#include "modB.h"
#include "emscripten/bind.h"

EMSCRIPTEN_BINDINGS(bar_class) {
  emscripten::class_<Bar>("Bar").constructor().function("sayHello",
                                                        &Bar::sayHello);
}
