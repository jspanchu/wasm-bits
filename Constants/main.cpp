#include <string>
#include "emscripten/bind.h"
#include <emscripten.h>

#define A 0
#define B 1
#define C 2

static constexpr int D = 3;

class Foo {
public:
  static const int E;
};

const int Foo::E = 4;
const std::string F = "5";
const char* G = "6";
#define VERSION "1.2.3"

EMSCRIPTEN_BINDINGS(foo_constants) {
  emscripten::constant("A", A);
  emscripten::constant("B", B);
  emscripten::constant("C", C);
  emscripten::constant("D", D);
  emscripten::constant("Foo_E", Foo::E);
  emscripten::constant("F", F);
  emscripten::constant("G", std::string(G));
  emscripten::constant("VERSION", std::string(VERSION));
}
