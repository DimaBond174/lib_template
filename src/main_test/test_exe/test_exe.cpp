#include <iostream>
#include "test1/test1_impl.h"
#include "test2/test2_impl.h"

int main(int argc, char** argv)
{  
  int res { 0 };
  int err_cnt  { 0 };

  res = do_Test1();
  if (1 == res)
  {
    std::cout << "[OK] do_Test1()" << std::endl;
  } else {
    std::cout << "[ERROR] do_Test1()" << std::endl;
    ++err_cnt;
  }

  res = do_Test2();
  if (1 == res)
  {
    std::cout << "[OK] do_Test2()" << std::endl;
  } else {
    std::cout << "[ERROR] do_Test2()" << std::endl;
    ++err_cnt;
  }

  std::cout << "======================================" << std::endl;
  std::cout << "ERRORs: " << err_cnt << std::endl;
  std::cout << "======================================" << std::endl;
  std::cout << "All tests done." << std::endl;
  return 0;
}
