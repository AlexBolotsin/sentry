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

int main(int argc, char** argv) {
  /* Create game
     init it
     then run it in ifinity loop
     return error code
   */
}
