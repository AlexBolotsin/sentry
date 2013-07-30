#include "keypressed.hpp"
#include "messages.hpp"

using namespace message;

KeyPressed::KeyPressed(input::Key key) {
}

void KeyPressed::exec() {
}

int KeyPressed::type() {
  return message::MSG_KEY_PRESSED;
}

