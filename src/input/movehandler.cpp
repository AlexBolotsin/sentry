#include "movehandler.hpp"
#include "messages.hpp"
#include "object.hpp"
#include "keypressed.hpp"
#include "keyreleased.hpp"

using namespace message;

void MoveHandler::target(Object* obj) {
  this->obj = obj;
}

void MoveHandler::listen(IMessage* msg) {
  if (msg->type() == message::MSG_KEY_PRESSED) {
    KeyPressed* pressed = dynamic_cast<KeyPressed*>(msg);
    switch(pressed->getKey()) {
    case input::KEY_W:
      obj->move(Object::MOVE_UP);
      break;
    case input::KEY_S:
      obj->move(Object::MOVE_DOWN);
      break;
    case input::KEY_A:
      obj->move(Object::MOVE_LEFT);
      break;
    case input::KEY_D:
      obj->move(Object::MOVE_RIGHT);
      break;
    default:
      break;
    }
  }
  if (msg->type() == message::MSG_KEY_RELEASED) {
    KeyReleased* released = dynamic_cast<KeyReleased*>(msg);
    switch(released->getKey()) {
    case input::KEY_W:
      obj->dontMove(Object::MOVE_UP);
      break;
    case input::KEY_S:
      obj->dontMove(Object::MOVE_DOWN);
      break;
    case input::KEY_A:
      obj->dontMove(Object::MOVE_LEFT);
      break;
    case input::KEY_D:
      obj->dontMove(Object::MOVE_RIGHT);
      break;
    default:
      break;
    }
  }
}
