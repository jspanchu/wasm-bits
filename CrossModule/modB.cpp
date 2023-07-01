#include "modB.h"
#include <iostream>

void Bar::sayHello(const std::string &name) {
  std::cout << "Hello " << name << std::endl;
}
