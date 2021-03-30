#include <iostream>
#include "message.h"

//retorna data e hora da mensagem
std::string Message::getDateTime() {
  returh this->dateTime;
}

//seta data e hora da mensagem
void Message::setDateTime(std::string dateTime) {
  this->dateTime = dateTime;
}

//retorna id do usuário que enviou mensagem
size_t Message::getSendBy() {
  return this->sendBy;
}

//seta id do usuário que enviou mensagem
void Message::setSendBy(size_t sendBy) {
  this->sendBy = sendBy;
}

//retorna conteúdo da mensagem
std::string Message::getContent() {
  this->content;
}

//seta conteúdo da mensagem
void Message::setContent(std::string content) {
  this->content = content;
}

//construtor
Message::Message(){}

//destrutor
Message::~Message(){}