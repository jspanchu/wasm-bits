#include "bar.h"
#include <iostream>

void Bar::sayHello(const std::string &name) {
  std::cout << "Hello " << name << " from " << __FILE__ << ":" << __LINE__
            << '\n';
}
