#include <iostream>

#include "GLRenderer.h"

namespace {
GLuint compile_shader(GLenum shaderType, const char *src) {
  GLuint shader = glCreateShader(shaderType);
  glShaderSource(shader, 1, &src, NULL);
  glCompileShader(shader);

  GLint isCompiled = 0;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
  if (!isCompiled) {
    GLint maxLength = 0;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);
    char *buf = (char *)malloc(maxLength + 1);
    glGetShaderInfoLog(shader, maxLength, &maxLength, buf);
    printf("%s\n", buf);
    free(buf);
    return 0;
  }

  return shader;
}

GLuint create_program(GLuint vertexShader, GLuint fragmentShader) {
  GLuint program = glCreateProgram();
  glAttachShader(program, vertexShader);
  glAttachShader(program, fragmentShader);
  glBindAttribLocation(program, 0, "apos");
  glBindAttribLocation(program, 1, "acolor");
  glLinkProgram(program);
  return program;
}
} // namespace

void GLRenderer::init() {
  std::cout << "Initializing GLRenderer\n";
  Renderer::init();

  EmscriptenWebGLContextAttributes attr;
  emscripten_webgl_init_context_attributes(&attr);
#ifdef EXPLICIT_SWAP
  attr.explicitSwapControl = 1;
#endif
  attr.majorVersion = 2;
  m_ctx = emscripten_webgl_create_context("#canvas", &attr);
  if (!m_ctx) {
    std::cerr << "Failed to create WebGL2 context\n";
  }
  emscripten_webgl_make_context_current(m_ctx);

  const char vertex_shader[] = "#version 100\n"
                               "attribute vec4 apos;"
                               "attribute vec4 acolor;"
                               "varying vec4 color;"
                               "void main() {"
                               "color = acolor;"
                               "gl_Position = apos;"
                               "}";
  GLuint vs = compile_shader(GL_VERTEX_SHADER, vertex_shader);

  const char fragment_shader[] = "#version 100\n"
                                 "precision lowp float;"
                                 "varying vec4 color;"
                                 "void main() {"
                                 "gl_FragColor = color;"
                                 "}";
  GLuint fs = compile_shader(GL_FRAGMENT_SHADER, fragment_shader);

  m_program = create_program(vs, fs);
  glUseProgram(m_program);

  glGenBuffers(1, &m_vbo);
  glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
  glBufferData(GL_ARRAY_BUFFER, m_vertices_and_colors.size() * sizeof(float), m_vertices_and_colors.data(),
               GL_STATIC_DRAW);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 20, 0);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 20, (void *)8);
  if (glGetError() != GL_NO_ERROR) {
    std::cerr
        << "glVertexAttribPointer with GL_UNSIGNED_INT_2_10_10_10_REV failed\n";
  }
}

void GLRenderer::draw() {
  emscripten_webgl_make_context_current(m_ctx);

  glUseProgram(m_program);

  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);

  glClearColor(0.3f, 0.3f, 0.3f, 1);
  glClear(GL_COLOR_BUFFER_BIT);
  glDrawArrays(GL_TRIANGLES, 0, 3);
  emscripten_webgl_commit_frame();
}
