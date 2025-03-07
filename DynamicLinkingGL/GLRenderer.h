#pragma once
#include "Renderer.h"
#include <GLES3/gl3.h>
#include <emscripten/html5.h>

class GLRenderer : public Renderer
{
  EMSCRIPTEN_WEBGL_CONTEXT_HANDLE m_ctx;
  GLuint m_program;
  GLuint m_vbo;
public:
  void init() override;
  void draw() override;
};