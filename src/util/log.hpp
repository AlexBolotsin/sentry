#ifndef LOG_HPP
#define LOG_HPP

#include <sstream>
#include <string>
#include <typeinfo>

#define LOG_MSG(A) { std::stringstream strm;	\
    strm << typeid(*this).name() << " " << A;	\
    Log::detail(strm.str().c_str()); }

class Log {
public:
  static void error(const char*);
  static void detail(const char*);
};

#endif
