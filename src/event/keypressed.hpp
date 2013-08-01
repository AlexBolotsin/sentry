#ifndef KEYPRESSED_HPP
#define KEYPRESSED_HPP

#include "imessage.hpp"
#include "input.hpp"

namespace message {

class KeyPressed : public IMessage {
  input::Key key;
public:
  KeyPressed(input::Key key);
  input::Key getKey();
  void exec();
  int type();
};

};

#endif
