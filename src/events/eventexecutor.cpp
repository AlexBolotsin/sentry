#include "eventexecutor.h"
#include "event.h"

EventExecutor::EventExecutor() {
}

void EventExecutor::executeChain(Event* event) {
    while (event) {
        while (event->wait()) {}
        event->execute();
        event = event->getNext();
    }
}
