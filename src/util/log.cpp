#include "log.hpp"
#include <iostream>

void Log::error(const char* msg) {
  std::cout << "ERROR " << msg << std::endl;
}

void Log::detail(const char* msg) {
  std::cout << "DETAIL " << msg << std::endl;
}
