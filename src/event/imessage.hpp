#ifndef IMESSAGE_HPP
#define IMESSAGE_HPP

class IMessage {
public:
  virtual ~IMessage() {}

  virtual void exec() = 0;
  virtual int type() = 0;
};

#endif
