#include <iostream>
#include "user.h"

std::string User::getEmail() {
  return this->email;
}

std::string User::getPassword() {
  return this->password;
}

size_t User::getId() {
  return this->id;
}


//construtor
User::User(size_t id, std::string name, std::string email, std::string password) {
  this->id = id;
  this->name = name;
  this->email = email;
  this->password = password;
}

//destrutor
User::~User() {} 
