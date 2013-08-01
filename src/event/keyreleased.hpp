#ifndef KEYRELEASED_HPP
#define KEYRELEASED_HPP

#include "imessage.hpp"
#include "input.hpp"

namespace message {

class KeyReleased : public IMessage {
  input::Key key;
public:
  KeyReleased(input::Key key);
  input::Key getKey();
  void exec();
  int type();
};

};

#endif
