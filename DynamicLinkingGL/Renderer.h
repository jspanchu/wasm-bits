#pragma once
#include <vector>

class Renderer {
public:
  virtual void init();
  virtual void draw() = 0;

protected:
  std::vector<float> m_vertices_and_colors;
};
