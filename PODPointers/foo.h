#pragma once
#include <string>
#include <vector>

class Foo {
public:
  void setArray(int *p, int n);
  void setArray(int p[4]);
  int *getArray();
  int getNumberOfElements() { return this->buffer.size(); }

  void setArray3D(int v[2][3][4]);
  int* getArray3D();

private:
  std::vector<int> buffer;
  int buffer3d[2][3][4] = {};
};
