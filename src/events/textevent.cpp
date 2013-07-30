#include "textevent.h"
#include <iostream>

TextEvent::TextEvent()
{
}

void TextEvent::execute() {
  std::cout << text << std::endl;
}

void TextEvent::setText(std::string text) {
  this->text = text;
}
