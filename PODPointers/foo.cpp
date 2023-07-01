#include "foo.h"

void Foo::setArray(int *p, int n) { this->buffer.assign(p, p + n); }

void Foo::setArray(int p[4]) { this->buffer.assign(p, p + 4); }

int *Foo::getArray() { return this->buffer.data(); }

void Foo::setArray3D(int v[2][3][4]) {
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 4; ++k) {
        this->buffer3d[i][j][k] = v[i][j][k];
      }
    }
  }
}

int *Foo::getArray3D() { return &this->buffer3d[0][0][0]; }
