#ifndef EVENT_H
#define EVENT_H

#include <time.h>

class Event
{
    unsigned int delay;
    Event* next;
    time_t endTime;
public:
    Event();
    virtual ~Event();

    void setDelay(int delay);
    void setNextEvent(Event* next);
    Event* getNext();
    bool wait();
    virtual void execute() = 0;

};

#endif // EVENT_H
