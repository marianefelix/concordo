#include <iostream>
#include <vector>
#include "server.h"

//retorna nome do servidor
std::string Server::getName() {
  return this->name;
}

//seta nomde do servidor
void Server::setName(const std::string name) {
  this->name = name;
}

//retorna id do dono do servidor
size_t Server::getServerOwnerId() {
  return this->serverOwnerId;
}

//seta id do usuário dono do servidor
void Server::setServerOwnerId(size_t id) {
  this->serverOwnerId = id;
}

//retorna descrição do servidor
std::string Server::getDescription() {
  return this->description;
}

//seta descrição do servidor
void Server::setDescription(const std::string description) {
  this->description = description;
}

//retorna código de convite do servidor
std::string Server::getInviteCode() {
  return this->inviteCode;
}

//seta código de convite do servidor
void Server::setInviteCode(const std::string code) {
  this->inviteCode = code;
}

//construtor
Server::Server() {
  this->description = "";
  this->inviteCode = "";
}

//destrutor
Server::~Server() {}