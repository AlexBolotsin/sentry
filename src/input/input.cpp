#include "input.hpp"

#include <SDL/SDL.h>
#include "quit.hpp"
#include "keypressed.hpp"
#include "keyreleased.hpp"
#include "log.hpp"

using namespace input;

Key convertKey(SDLKey key) {
  Key converted = KEY_NONE;
  switch(key) {
  case SDLK_DOWN:
    converted = KEY_DOWN;
    break;
  case SDLK_UP:
    converted = KEY_UP;
    break;
  case SDLK_LEFT:
    converted = KEY_LEFT;
    break;
  case SDLK_RIGHT:
    converted = KEY_RIGHT;
    break;
  case SDLK_SPACE:
    converted = KEY_SPACE;
    break;
  case SDLK_RETURN:
    converted = KEY_ENTER;
    break;
  case SDLK_ESCAPE:
    converted = KEY_ESC;
    break;
  case SDLK_w:
    converted = KEY_W;
    break;
  case SDLK_a:
    converted = KEY_A;
    break;
  case SDLK_s:
    converted = KEY_S;
    break;
  case SDLK_d:
    converted = KEY_D;
    break;
  case SDLK_z:
    converted = KEY_Z;
    break;
  case SDLK_x:
    converted = KEY_X;
    break;
  default:
    break;
  }
  return converted;
}

Input::Input() : listener(NULL) {
}

void Input::processInput() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_KEYDOWN:
      {
      Key key = convertKey(event.key.keysym.sym);
      setState(key, STATE_PRESSED);
      message::KeyPressed keyPressed(key);
      listener->listen(&keyPressed);
      continue;
      }
    case SDL_KEYUP: {
      Key key = convertKey(event.key.keysym.sym);
      setState(key, STATE_RELEASED);
      message::KeyReleased keyReleased(key);
      listener->listen(&keyReleased);
      continue;
    }
    case SDL_QUIT:
      message::Quit quit;
      listener->listen(&quit);
      continue;
    }
  }
}

void Input::sendMessage(IMessage* msg) {
  if(!listener) return;
  LOG_MSG(__FUNCTION__ << " Sending message " << (int)msg->type());
  listener->listen(msg);
}

bool Input::isPressed(Key key) {
  return getState(key) == STATE_RELEASED ? true : false;
}

void Input::setState(Key key, State state) {
  LOG_MSG(__FUNCTION__ << (int)key << (int)state);
  keys[key] = state;
}

State Input::getState(Key key) {
  auto res = keys.find(key);
  return res->second;
}

void Input::setListener(IListener* listener) {
  this->listener = listener;
}
