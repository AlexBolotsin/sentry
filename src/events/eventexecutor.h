#ifndef EVENTEXECUTOR_H
#define EVENTEXECUTOR_H

class Event;

class EventExecutor
{
public:
    EventExecutor();

    void executeChain(Event* event);
};

#endif // EVENTEXECUTOR_H
