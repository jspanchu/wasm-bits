#include <emscripten.h>
#include <emscripten/bind.h>

bool exists(emscripten::val v, const std::string& key) {
  return emscripten::val(key).in(v);
}

EMSCRIPTEN_BINDINGS(funcs) {
  emscripten::function("exists", &exists);
}
