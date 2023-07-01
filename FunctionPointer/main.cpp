#include <emscripten.h>
#include <emscripten/bind.h>
#include <iostream>
#include <string>

static int runCallback(emscripten::val arg) {
  int fp = emscripten::val::module_property("addFunction")(arg, std::string("vi")).as<int>();
  std::cout << "fp: " << fp << std::endl;
  void (*f)(int) = reinterpret_cast<void (*)(int)>(fp);
  f(7);
  std::cout << "ok" << std::endl;
  return 0;
}

EMSCRIPTEN_BINDINGS(fptr_bindings) {
    emscripten::function("runCallback", &runCallback);
}
