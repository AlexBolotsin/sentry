#ifndef ILISTENER_HPP
#define ILISTENER_HPP

#include "imessage.hpp"

class IListener {
public:
  virtual ~IListener() {}

  virtual void listen(IMessage* msg) = 0;
};

#endif
