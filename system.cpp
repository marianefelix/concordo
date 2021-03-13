#include "system.h"

#include <sstream>
#include <algorithm>


/* comandos do sistema */

std::string System::quit() {
  return "Saindo do Concordo...";
}

std::string System::create_user(const std::string email, const std::string password, const std::string name) {
  size_t usersSize = users.size();
  bool isEmailAlredyUsed = false;

  if (usersSize != 0) {
    for(size_t i= 0; i < usersSize; i++) {
      std::string otherEmail = users[i].getEmail();
      if (email.compare(otherEmail) == 0) {
        isEmailAlredyUsed = true;
        break;
      }
    }
  }

  if (!isEmailAlredyUsed) {
    //cria novo usuário
    User* user = new User(usersSize + 1, name, email, password);
    //adiciona user no vetor de usuários
    users.push_back(*user);

    return "Usuário criado com sucesso!";
  } else {
    return "Usuário já existe";
  }
}

std::string System::login(const std::string email, const std::string password) {
  size_t usersSize = users.size();
  std::string otherEmail, otherPassword;
  bool isUserLogged = false;

  if (usersSize != 0) {
    for(size_t i= 0; i < usersSize; i++) {
      otherEmail = users[i].getEmail();
      otherPassword = users[i].getPassword();

      if (email.compare(otherEmail) == 0 && password.compare(otherPassword) == 0) {
        isUserLogged = true;
        loggedUserId = users[i].getId();
 
        break;
      }
    }

    if (isUserLogged) {
      return "Logado como " + otherEmail;
    } else {
      return "Senha ou usuário inválidos!";
    }
  } else {
    return "Nenhum usuário foi criado ainda.";
  }
}

std::string System::disconnect() {
  return "disconnect NÃO IMPLEMENTADO";
}

std::string System::create_server(const std::string name) {
  return "create_server NÃO IMPLEMENTADO";
}

std::string System::set_server_desc(const std::string name, const std::string description) {
  return "set_server_desc NÃO IMPLEMENTADO";
}

std::string System::set_server_invite_code(const std::string name, const std::string code) {
  return "set_server_invite_code NÃO IMPLEMENTADO";
}

std::string System::list_servers() {
  return "list_servers NÃO IMPLEMENTADO";
}

std::string System::remove_server(const std::string name) {
  return "remove_server NÃO IMPLEMENTADO";
}

std::string System::enter_server(const std::string name, const std::string code) {
  return "enter_server NÃO IMPLEMENTADO";
}

std::string System::leave_server() {
  return "leave_server NÃO IMPLEMENTADO";
}

std::string System::list_participants() {
  return "list_participants NÃO IMPLEMENTADO";
}

std::string System::list_channels() {
  return "list_channels NÃO IMPLEMENTADO";
}

std::string System::create_channel(const std::string name, const std::string type) {
  return "create_channel NÃO IMPLEMENTADO";
}

std::string System::enter_channel(const std::string name) {
  return "enter_channel NÃO IMPLEMENTADO";
}

std::string System::leave_channel() {
  return "leave_channel NÃO IMPLEMENTADO";
}

std::string System::send_message(const std::string message) {
  return "send_message NÃO IMPLEMENTADO";
}

std::string System::list_messages() {
  return "list_messages NÃO IMPLEMENTADO";
}

/* IMPLEMENTAR MÉTODOS PARA OS COMANDOS RESTANTES */