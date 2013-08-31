#ifndef MOVE_HANDLER_HPP
#define MOVE_HANDLER_HPP

#include "ilistener.hpp"

class Object;

class MoveHandler : public IListener {
  Object* obj;
public:
  /* Set target for movements. 
   */
  void target(Object* obj);
  /* Listens to key pressed and released to set up object direction.
   */
  virtual void listen(IMessage* msg);
};

#endif
