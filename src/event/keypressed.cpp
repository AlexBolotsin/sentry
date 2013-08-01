#include "keypressed.hpp"
#include "messages.hpp"

using namespace message;

KeyPressed::KeyPressed(input::Key key) {
  this->key = key;
}

input::Key KeyPressed::getKey() {
  return key;
}

void KeyPressed::exec() {
}

int KeyPressed::type() {
  return message::MSG_KEY_PRESSED;
}

