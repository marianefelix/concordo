#include "system.h"
#include <algorithm>


//função de apoio que retorna se duas strings são iguais
bool isEqual(std::string firstString, std::string secondString) {
  return firstString.compare(secondString) == 0;
}

/* comandos do sistema */

std::string System::quit() {
  return "Saindo do Concordo...";
}

std::string System::create_user(const std::string email, const std::string password, const std::string name) {
  std::vector<User>::iterator user_it;
  bool userAlredyExists = false;

  //procura usuário por email
  user_it = std::find_if(users.begin(), users.end(), [email](User user){
    return isEqual(email, user.getEmail());
  });

  userAlredyExists = user_it != users.end();

  //verifica se usuário não existe
  if (!userAlredyExists) {
    //cria novo usuário
    User user;
    user.setId(users.size() + 1);
    user.setName(name);
    user.setEmail(email);
    user.setPassword(password);

    //adiciona user no vetor de usuários
    users.push_back(user);

    return "Usuário criado com sucesso!";
  }

  return "Usuário já existe";
}

std::string System::login(const std::string email, const std::string password) {
  if (!users.empty()) {
    std::vector<User>::iterator user_it;
    bool areCredentialsValid = false;

    //procura usuário pelo email e senha
    user_it = std::find_if(users.begin(), users.end(), [email, password](User user){
      return isEqual(email, user.getEmail()) && isEqual(password, user.getPassword());
    });

    areCredentialsValid = user_it != users.end();

    //verifica credenciais
    if (areCredentialsValid) {
      loggedUserId = user_it->getId();
      return "Logado como " + user_it->getEmail();
    }

    return "Senha ou usuário inválidos!";
  }

  return "Nenhum usuário foi criado ainda.";
}

std::string System::disconnect() {
  //verifica se tem algum usuário logado
  if (loggedUserId != 0) {
    //recupera email do usuário logado
    std::string user = users[loggedUserId - 1].getEmail();

    //modifica variável que guarda id de usuário logado
    loggedUserId = 0;

    return "Desconectando usuário " + user;
  }
  
  return "Não está conectado";
}

std::string System::create_server(const std::string name) {
  if (loggedUserId != 0) {
    std::vector<Server>::iterator server_it;
    bool serverAlreadyExists = false;

    //procura servidor pelo nome
    server_it = std::find_if(servers.begin(), servers.end(), [name](Server server){
      return isEqual(name, server.getName());
    });

    serverAlreadyExists = server_it != servers.end();

    if (!serverAlreadyExists) {
      //cria novo servidor
      Server server;

      server.setName(name);
      server.setServerOwnerId(loggedUserId);

      //adiciona server no vetor de servidores
      servers.push_back(server);

      std::cout << server.getDescription() << server.getInviteCode();
      return "Servidor criado com sucesso!";
    }

    return "Já existe um servidor com esse nome";
  }

  return "Você precisa estar logado para criar um servidor";
}

std::string System::set_server_desc(const std::string name, const std::string description) {
  if (loggedUserId != 0) {
    if (!servers.empty()) {
      std::vector<Server>::iterator server_it;    
      bool serverExists = false;

      //procura servidor por nome
      server_it = std::find_if(servers.begin(), servers.end(), [name](Server server){
        return isEqual(name, server.getName());
      });

      serverExists = server_it != servers.end();

      //verifica se servidor não existe
      if (!serverExists) {
        return "Servidor ‘" + name + "’ não existe";
      } else if(loggedUserId != server_it->getServerOwnerId()) { //verifica diferença de ids dos usuários
        return "Você não pode alterar a descrição de um servidor que não foi criado por você";
      } else {
        //seta descrição do servidor
        server_it->setDescription(description);
        return "Descrição do servidor ‘" + name + "’ modificada!";
      }
    }

    return "Nenhum servidor foi criado ainda";
  }

  return "Você precisa estar logado para alterar a descrição do servidor";
}

std::string System::set_server_invite_code(const std::string name, const std::string code) {
  if (loggedUserId != 0) {  
    if (!servers.empty()) {
      std::vector<Server>::iterator server_it;    
      bool serverExists = false;

      //procura servidor por nome
      server_it = std::find_if(servers.begin(), servers.end(), [name](Server server){
        return isEqual(name, server.getName());
      });

      serverExists = server_it != servers.end();

      //verifica se servidor não existe
      if (!serverExists) {
        return "Servidor ‘" + name + "’ não existe";
      } else if(loggedUserId != server_it->getServerOwnerId()) { //verifica diferença de ids dos usuários
        return "Você não pode alterar o código de convite de um servidor que não foi criado por você";
      } else {
        //verifica se code não é vazio
        if (code != "") {
          //seta código de convite do servidor
          server_it->setInviteCode(code);
          return "Código de convite do servidor ‘" + name + "’ modificado!";
        } else {
          server_it->setInviteCode("");
          return "Código de convite do servidor ‘" + name + "’ removido!";
        }
      }
    }

    return "Nenhum servidor foi criado ainda";
  }

  return "Você precisa estar logado para alterar o código de convite do servidor";
}

std::string System::list_servers() {
  //percorre vetor de servidores
  for (size_t i = 0; i < servers.size(); i++) {
    std::string serverIs = "fechado";
    if (servers[i].getInviteCode() == "") {
      serverIs = "aberto";
    }

    if (i != servers.size() - 1) {
      std::cout << servers[i].getName() + " " + servers[i].getDescription() + " " + serverIs << std::endl;
    } else {
      std::cout << servers[i].getName() + " " + servers[i].getDescription() + " " + serverIs;
    }
  }

  return "Nenhum servidor criado";
}

std::string System::remove_server(const std::string name) {
  if (loggedUserId != 0) {
    if (!servers.empty()) {
      std::vector<Server>::iterator server_it;    
      bool serverExists = false;

      //procura servidor por nome
      server_it = std::find_if(servers.begin(), servers.end(), [name](Server server){
        return isEqual(name, server.getName());
      });

      serverExists = server_it != servers.end();

      if (!serverExists) {
        return "Servidor ‘" + name + "’ não existe";
      } else if(loggedUserId != server_it->getServerOwnerId()) {
        return "Você não é o dono do servidor ‘" + name + "’";
      } else {
        //deleta servidor do vetor
        servers.erase(server_it);
        return "Servidor ‘" + name + "’ removido";
      }
    }

    return "Nenhum servidor foi criado ainda";
  }

  return "Você precisa estar logado para alterar o código de convite do servidor";
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

//construtor
System::System() {}

//destrutor
System::~System() {}