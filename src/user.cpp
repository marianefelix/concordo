#include <iostream>
#include "user.h"

size_t User::getId() {
  return this->id;
}

void User::setId(size_t id) {
  this->id = id;
}

std::string User::getEmail() {
  return this->email;
}

void User::setEmail(std::string email) {
  this->email = email;
}
std::string User::getName() {
  return this->name;
}

void User::setName(std::string name) {
  this->name = name;
}

std::string User::getPassword() {
  return this->password;
}

void User::setPassword(std::string password) {
  this->password = password;
}

//construtor
User::User() {}

//destrutor
User::~User() {} 
