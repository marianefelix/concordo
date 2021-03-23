#include <iostream>
#include "user.h"

//retorna id de usuário
size_t User::getId() {
  return this->id;
}

//seta id de usuário
void User::setId(size_t id) {
  this->id = id;
}

//retorna email de usuário
std::string User::getEmail() {
  return this->email;
}

//seta email de usuário
void User::setEmail(std::string email) {
  this->email = email;
}

//retorna nome de usuário
std::string User::getName() {
  return this->name;
}

//seta nome de usuário
void User::setName(std::string name) {
  this->name = name;
}

//retorna senha de usuário
std::string User::getPassword() {
  return this->password;
}

//seta senha de usuário
void User::setPassword(std::string password) {
  this->password = password;
}

//construtor
User::User() {}

//destrutor
User::~User() {}
