#include "executor.h"

#include <istream>
#include <algorithm>
#include <ostream>
#include <iostream>
#include <sstream>
#include <queue>

/*
  função de apoio que recebe um istringstream e
  lê todo texto restante até o fim da linha
*/
std::string restOf(std::istringstream &ss) {
  std::string rest;

  //lê o resto da linha
  getline(ss, rest, '\0');

  //verifica se primeiro caractere é um espaço
  if (rest != "" && (rest[0] == ' ' || rest[0] == '\t')) {
    //descarta primeiro caractere
    rest = rest.substr(1);
  }

  return rest;
}

//funcao de apoio para remover aspas de uma string
std::string removeQuotes(std::string string) {
  //verifica se string recebida tem aspas e as remove
  if (string.at(0) == '\"' || string.at(string.length() - 1) == '\"') {
    string.erase(
      std::remove(string.begin(), string.end(), '\"' ),
      string.end()
    );
  }

  return string;
}

//processa entradas e saídas
void Executor::start(std::istream &inputStream, std::ostream &outputStream) {
  std::string line, output;
  this->logout = false;

  while (!this->logout) {
    if (std::getline(inputStream, line)) {
      output = line_process(line);
      outputStream << output << std::endl;
    }
  }
}

/*
  processa cada linha de comando e executa o método 
  correspondente, caso o comando seja válido
*/
std::string Executor::line_process(std::string line) {
  std::istringstream buf(line);
  std::string commandName;
  buf >> commandName;

  if (commandName.empty()) {
    return "Comando Inválido <vazio>";
  }

  if (commandName == "quit" ) {
    this->logout = true;
    return system->quit();
  }

  else if (commandName == "create-user") {
    std::string email, password, name;
    
    buf >> email;
    buf >> password;
    name = restOf(buf);

    return system->create_user(email, password, name);
  }

  else if (commandName == "login") {
    std::string email, password;
  
    buf >> email;
    buf >> password;

    return system->login(email, password);
  }

  else if (commandName == "disconnect") {
    return system->disconnect();
  }

  else if (commandName == "create-server") {
    std::string name;
    buf >> name;

    return system->create_server(name);
  }

  else if (commandName == "set-server-desc") {
    std::string name, description;
    buf >> name;
    description = restOf(buf);

    std::string newDescription = (description != "") ? removeQuotes(description) : description;

    return system->set_server_desc(name, newDescription);
  }

  else if (commandName == "set-server-invite-code") {
    std::string name, code;

    buf >> name;
    buf >> code;

    return system->set_server_invite_code(name, code);
  }

  else if (commandName == "list-servers") {
    return system->list_servers();
  }

  else if (commandName == "remove-server") {
    std::string name;
    buf >> name;

    return system->remove_server(name);
  }

  else if (commandName == "enter-server") {
    std::string name, code;

    buf >> name;
    buf >> code;

    return system->enter_server(name, code);
  }

  else if (commandName == "leave-server") {
    return system->leave_server();
  }

  else if (commandName == "list-participants") {
    return system->list_participants();
  }

  else if (commandName == "list-channels") {
    return system->list_channels();
  }

  else if (commandName == "create-channel") {
    std::string name, type;

    buf >> name;
    buf >> type;

    return system->create_channel(name, type);
  }

  else if (commandName == "enter-channel") {
    std::string name;
    buf >> name;

    return system->enter_channel(name);
  }

  else if (commandName == "leave-channel") {
    return system->leave_channel();
  }
  
  else if (commandName == "send-message") {
    std::string message;
    message = restOf(buf);

    return system->send_message(message);
  }
  
  else if (commandName == "list-messages") {
    return system->list_messages();
  }

  else {
    return "Comando não reconhecido [" + commandName + "]";
  }
}

/* 
  construtor que recebe uma referência do sistema
  que vai operar e guarda o seu endereço para 
  executar as operações
*/
Executor::Executor(System &system) {
  //inicializa logout 
  this->logout = false;
  this->system = &system;
}

//destrutor
Executor::~Executor() {}


