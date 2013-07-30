#ifndef KEYPRESSED_HPP
#define KEYPRESSED_HPP

#include "imessage.hpp"
#include "input.hpp"

namespace message {

class KeyPressed : public IMessage {
public:
  KeyPressed(input::Key key);
  void exec();
  int type();
};

};

#endif
