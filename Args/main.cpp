#include <cstdlib>
#include <iostream>

int main(int argc, char* argv[])
{
  const char* name = argv[0];
  const int number1 = std::atoi(argv[1]);
  const int number2 = std::atoi(argv[2]);
  std::cout << "argv[0]:" << name << std::endl;
  std::cout << "argv[1]:" << number1 << std::endl;
  std::cout << "argv[2]:" << number2 << std::endl;
  return 0;
}
