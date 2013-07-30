#include "event.h"

#ifndef NULL
#define NULL 0
#endif

Event::Event() : delay(0), next(NULL), endTime(0) {
}

Event::~Event() {
}

void Event::setDelay(int delay) {
    this->delay = delay;
}

void Event::setNextEvent(Event* next) {
    this->next = next;
}

Event* Event::getNext() {
    return next;
}

bool Event::wait() {
    if (!endTime)
        endTime = time(NULL) + delay/1000;
    return endTime > time(NULL);
}
