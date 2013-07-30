/*
Event* initChain() {
  TextEvent* event = new TextEvent();
  event->setText("Hello");
  event->setDelay(2000);
    
  TextEvent* child = new TextEvent();
  child->setDelay(3000);
  child->setText("My name is Marry");
  event->setNextEvent(child);

  return event;
}

void freeChain(Event* chain) {
  while (chain) {
    Event* next = chain->getNext();
    delete chain;
    chain = next;
  }
}
*/

#include "game.hpp"

int main(int argc, char** argv) {
  application::Game game;
  game.run();
  return 0;
}
