#include "quit.hpp"
#include "messages.hpp"

using message::Quit;

void Quit::exec() {
}

int Quit::type() {
  return MSG_QUIT;
}
