#ifndef QUIT_HPP
#define QUIT_HPP

#include "imessage.hpp"

namespace message {

class Quit : public IMessage {
  void exec();
  int type();
};

};
#endif
