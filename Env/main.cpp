#include <cstdlib>
#include <iostream>

int main() {
  const char *msg = std::getenv("MESSAGE");
  std::cout << msg << std::endl;
  return 0;
}
