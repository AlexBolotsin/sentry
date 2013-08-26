#ifndef MOVE_HANDLER_HPP
#define MOVE_HANDLER_HPP

class MoveHandler : public IListener {
  Object* target;
public:
  void target(Object* obj) {
    target = obj;
  }
  
  virtual void listen(IMessage* msg) {
    if (msg->type() == MSG_KEY_PRESSED) {
      target->
    }
  }
};

#endif
