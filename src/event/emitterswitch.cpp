#include "emitterswitch.hpp"

void EmitterSwitch::addListener(IListener* listener) {
  listeners.push_back(listener);
}

void EmitterSwitch::listen(IMessage* msg) {
  for (IListener* listener : listeners) {
    listener->listen(msg);
  }
}
