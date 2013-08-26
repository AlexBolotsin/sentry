#ifndef ILISTENER_HPP
#define ILISTENER_HPP

#include "imessage.hpp"

class IListener {
protected:
  IListener* listener;
public:
  IListener() : listener(NULL) {}
  virtual ~IListener() {}

  virtual void listen(IMessage* msg) = 0;
  virtual void setListener(IListener* listener) {
    this->listener = listener;
  }
};

#endif
