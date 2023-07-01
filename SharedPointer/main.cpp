#include "emscripten/bind.h"
#include <iostream>
#include <memory>

using namespace emscripten;

class MyClass {
public:
  MyClass()
    : x(0)
  {}
  MyClass(int x, std::string y)
    : x(x)
    , y(y)
  {}
  ~MyClass()
  {
    std::cout << "Deleted!" << std::endl;
  }

  void incrementX() {
    ++x;
  }

  int getX() const { return x; }
  void setX(int x_) { x = x_; }

  static std::string getStringFromInstance(const MyClass& instance) {
    return instance.y;
  }

private:
  int x;
  std::string y;
};

// Binding code
EMSCRIPTEN_BINDINGS(my_class_example) {
  class_<MyClass>("MyClass")
    .smart_ptr_constructor("MyClass", &std::make_shared<MyClass>)
    .function("incrementX", &MyClass::incrementX)
    .property("x", &MyClass::getX, &MyClass::setX)
    .class_function("getStringFromInstance", &MyClass::getStringFromInstance)
    ;
}
