#include <iostream>
#include "channel.h"

//retorna nome do canal
std::string Channel::getName() {
  return this->name;
}

//seta nome do canal
void Channel::setName(std::string name) {
  this->name = name;
}

//construtor
Channel::Channel() {}

//destrutor
Channel::~Channel() {}
