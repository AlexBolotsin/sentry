#ifndef MOVE_HANDLER_HPP
#define MOVE_HANDLER_HPP

#include "ilistener.hpp"

class Object;

class MoveHandler : public IListener {
  Object* obj;
public:
  void target(Object* obj);
  virtual void listen(IMessage* msg);
};

#endif
