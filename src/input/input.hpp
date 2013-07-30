#ifndef INPUT_HPP
#define INPUT_HPP

#include <map>
#include "ilistener.hpp"

namespace input {

enum Key {
  KEY_NONE = 0,
  KEY_SPACE,
  KEY_ENTER,
  KEY_ESC,
  KEY_W,
  KEY_A,
  KEY_S,
  KEY_D,
  KEY_Z,
  KEY_X,
  KEY_LEFT,
  KEY_RIGHT,
  KEY_UP,
  KEY_DOWN
};

enum State {
  STATE_NONE = 0,
  STATE_PRESSED,
  STATE_RELEASED
};

class Input {
  std::map<input::Key, input::State> keys;
public:
  Input();
  void processInput();
  void sendMessage(IMessage* msg);
  bool isPressed(input::Key key);

  void setListener(IListener* listener);
private:
  IListener* listener;

  void setState(input::Key key, input::State state);
  input::State getState(input::Key key);
};

};

#endif
