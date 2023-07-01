#include <thread>
#include <iostream>

int main(int, char**)
{
  std::thread t([](){
       std::cout << "Hello from thread " << std::this_thread::get_id() << std::endl;
      });
  t.join();
  return 0;
}
