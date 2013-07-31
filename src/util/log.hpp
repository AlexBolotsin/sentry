#ifndef LOG_HPP
#define LOG_HPP

#include <sstream>
#include <string>
#include <typeinfo>


#ifdef LOG
#define LOG_MSG(A) { std::stringstream strm;		\
    strm << typeid(*this).name() << " " <<		\
      std::hex << this <<				\
      std::dec << " " << A;				\
    Log::detail(strm.str().c_str()); }
#else
#define LOG_MSG(A) {}
#endif

class Log {
public:
  static void error(const char*);
  static void detail(const char*);
};

#endif
