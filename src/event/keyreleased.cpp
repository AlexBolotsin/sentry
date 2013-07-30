#include "keyreleased.hpp"
#include "messages.hpp"

using namespace message;

KeyReleased::KeyReleased(input::Key key) {
}

void KeyReleased::exec() {
}

int KeyReleased::type() {
  return message::MSG_KEY_RELEASED;
}
