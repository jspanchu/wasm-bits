#pragma once
#include <string>

class Foo {
public:
  virtual ~Foo() {}
  virtual std::string GetClassName();
  virtual std::string GetClassNameImplementation() = 0;
};
