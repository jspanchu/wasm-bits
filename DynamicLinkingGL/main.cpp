#include "GLRenderer.h"

namespace {
void draw(void *userData) {
  if (auto *renderer = static_cast<Renderer *>(userData)) {
    renderer->draw();
  }
}
} // namespace

int main(int argc, char **argv) {
  Renderer *renderer = new GLRenderer();
  renderer->init();
  emscripten_set_main_loop_arg(::draw, static_cast<void *>(renderer), 0, true);
  return 0;
}