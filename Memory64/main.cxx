#include <cstddef>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
  {
    std::vector<uint8_t> buffer;
    std::size_t numValues = 1024;
    for (int i = 0; i < argc; ++i) {
      if (std::string(argv[i]) == "-n") {
        std::stringstream sst;
        sst.str(argv[i + 1]);
        sst >> numValues;
        break;
      }
    }
    std::cout << "allocate " << numValues << "bytes.." << std::endl;
    buffer.resize(numValues);
    std::cout << "allocated " << buffer.size() << "bytes." << std::endl;
  }
  std::cout << "sizeof(int): " << sizeof(int) << std::endl;
  std::cout << "sizeof(long): " << sizeof(long) << std::endl;
  std::cout << "sizeof(long long): " << sizeof(long long) << std::endl;
  std::cout << "sizeof(unsigned): " << sizeof(unsigned) << std::endl;
  std::cout << "sizeof(unsigned long): " << sizeof(unsigned long) << std::endl;
  std::cout << "sizeof(unsigned long long): " << sizeof(unsigned long long)
            << std::endl;
  std::cout << "sizeof(std::size_t): " << sizeof(std::size_t) << std::endl;
  std::cout << "sizeof(float): " << sizeof(int) << std::endl;
  std::cout << "sizeof(double): " << sizeof(long) << std::endl;
  std::cout << "sizeof(int32_t): " << sizeof(int32_t) << std::endl;
  std::cout << "sizeof(int64_t): " << sizeof(int64_t) << std::endl;
  std::cout << "sizeof(void*): " << sizeof(void *) << std::endl;
  std::cout << "sizeof(0xABCD12345678ULL): " << sizeof(0xABCD12345678ULL)
            << std::endl;
  // std::size_t numValues = 1024;
  // for (int i = 0; i < argc; ++i)
  // {
  //   if (std::string(argv[i]) == "-n")
  //   {
  //     numValues = static_cast<std::size_t>(std::atoi(argv[i + 1]));
  //     break;
  //   }
  // }
  // uint8_t* arr = new uint8_t[numValues];
  // std::memset(arr, 0, numValues);
  return 0;
}