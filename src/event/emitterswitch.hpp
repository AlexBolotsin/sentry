#ifndef EMITTERSWITCH_HPP
#define EMITTERSWITCH_HPP

#include "ilistener.hpp"
#include <list>

class EmitterSwitch : public IListener {
  std::list<IListener*> listeners;
public:
  void addListener(IListener* listener);
  void listen(IMessage* msg);
};

#endif
