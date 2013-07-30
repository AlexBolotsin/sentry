#ifndef KEYRELEASED_HPP
#define KEYRELEASED_HPP

#include "imessage.hpp"
#include "input.hpp"

namespace message {

class KeyReleased : public IMessage {
public:
  KeyReleased(input::Key key);
  void exec();
  int type();
};

};

#endif
