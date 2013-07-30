#ifndef TEXTEVENT_H
#define TEXTEVENT_H

#include "string"
#include "event.h"

class TextEvent : public Event
{
  std::string text;
public:
    TextEvent();

    void setText(std::string text);
    virtual void execute();
};

#endif // TEXTEVENT_H
