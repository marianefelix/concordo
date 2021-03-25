#include "system.h"
#include <algorithm>


//função de apoio que retorna se duas strings são iguais
bool isEqual(std::string firstString, std::string secondString) {
  return firstString.compare(secondString) == 0;
}

/* comandos do sistema */

//sai do sistema
std::string System::quit() {
  return "Saindo do Concordo...";
}

//cria usuário
std::string System::create_user(const std::string email, const std::string password, const std::string name) {
  if (email == "" || name == "") {
    return "Email e nome de usuário não podem ser vazios";
  }

  bool userAlredyExists = false;

  //procura usuário por email
  auto user_it = std::find_if(
    users.begin(), 
    users.end(), 
    [email](User user) {
      return isEqual(email, user.getEmail());
    }
  );

  userAlredyExists = user_it != users.end();

  //verifica existência de usuário no sistema
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

//realiza login de usuário
std::string System::login(const std::string email, const std::string password) {
  if (!users.empty()) {
    bool areCredentialsValid = false;

    //procura usuário pelo email e senha
    auto user_it = std::find_if(
      users.begin(), 
      users.end(), 
      [email, password](User user) {
        return isEqual(email, user.getEmail()) && isEqual(password, user.getPassword());
      }
    );

    areCredentialsValid = user_it != users.end();

    //verifica credenciais
    if (areCredentialsValid) {
      /*
        verifica se usuário que está efetuando login no
        sistema é diferente do usuário que estava logado
        anterioriormente
      */
      if (user_it->getId() !=  loggedUserId) {
        serverNameConnected = "";
      }
      loggedUserId = user_it->getId();
      return "Logado como " + user_it->getEmail();
    }
    return "Senha ou usuário inválidos!";
  }
  return "Nenhum usuário foi criado ainda.";
}

//realiza logout de usuário
std::string System::disconnect() {
  //verifica se tem algum usuário logado
  if (loggedUserId != 0) {
    //recupera email do usuário logado
    std::string user = users[loggedUserId - 1].getEmail();

    //modifica variável que guarda id de usuário logado
    loggedUserId = 0;

    /*
      modifica variável que guarda nome de
      servidor que está sendo visualizado
    */
    serverNameConnected = "";

    return "Desconectando usuário " + user;
  }
  return "Não está conectado";
}

//cria servidor
std::string System::create_server(const std::string name) {
  if (loggedUserId != 0) {
    if (name == "") {
      return "O nome do servidor não pode ser vazio";
    }

    bool serverAlreadyExists = false;

    //procura servidor pelo nome
    auto server_it = std::find_if(
      servers.begin(), 
      servers.end(), 
      [name](Server server) {
        return isEqual(name, server.getName());
      }
    );

    serverAlreadyExists = server_it != servers.end();

    //verifica existência de servidor
    if (!serverAlreadyExists) {
      //cria novo servidor
      Server server;

      server.setName(name);
      server.setServerOwnerId(loggedUserId);

      //adiciona server no vetor de servidores
      servers.push_back(server);
      //adiciona dono do servidor na lista de participantes
      server.pushParticipantId(loggedUserId);

      return "Servidor criado com sucesso!";
    }
    return "Já existe um servidor com esse nome";
  }
  return "Você precisa estar logado para criar um servidor";
}

//altera descrição de servidor
std::string System::set_server_desc(const std::string name, const std::string description) {
  if (loggedUserId != 0) {
    if (!servers.empty()) {
      bool serverExists = false;

      //procura servidor por nome
      auto server_it = std::find_if(
        servers.begin(), 
        servers.end(), 
        [name](Server server) {
          return isEqual(name, server.getName());
        }
      );

      serverExists = server_it != servers.end();

      //verifica existência de servidor
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

//altera código de convite de servidor
std::string System::set_server_invite_code(const std::string name, const std::string code) {
  if (loggedUserId != 0) {
    if (!servers.empty()) {
      bool serverExists = false;

      //procura servidor por nome
      auto server_it = std::find_if(
        servers.begin(), 
        servers.end(), 
        [name](Server server) {
          return isEqual(name, server.getName());
        }
      );

      serverExists = server_it != servers.end();

      //verifica existência de servidor
      if (!serverExists) {
        return "Servidor ‘" + name + "’ não existe";
      } else if (loggedUserId != server_it->getServerOwnerId()) { //verifica diferença de ids dos usuários
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

//lista servidores cadastrados no sistema
std::string System::list_servers() {
  if (loggedUserId != 0) {
    if (!servers.empty()) {
      //percorre vetor de servidores
      for (size_t i = 0; i < servers.size(); i++) {
        std::string serverIs = 
          (servers[i].getInviteCode() == "")
            ? "aberto"
            : "fechado";

        std::string description = 
          (servers[i].getDescription() == "")
            ? "sem descrição" 
            : servers[i].getDescription();
        
        std::cout << servers[i].getName() + ": " + description + " - " + serverIs;

        if (i != servers.size() - 1) {
          std::cout << std::endl;
        }
      }

      return "";
    }
    return "Nenhum servidor criado ainda";
  }
  return "Você precisa estar logado para ver servidores";
}

//remove servidor do sistema
std::string System::remove_server(const std::string name) {
  if (loggedUserId != 0) {
    if (!servers.empty()) {
      bool serverExists = false;

      //procura servidor por nome
      auto server_it = std::find_if(
        servers.begin(), 
        servers.end(), 
        [name](Server server) {
          return isEqual(name, server.getName());
        }
      );

      serverExists = server_it != servers.end();

      //verifica existência de servidor
      if (!serverExists) {
        return "Servidor ‘" + name + "’ não existe";
      } else if(loggedUserId != server_it->getServerOwnerId()) {
        return "Você não é o dono do servidor ‘" + name + "’";
      } else {
        //remove servidor do vetor de servidores
        servers.erase(server_it);
        return "Servidor ‘" + name + "’ removido";
      }
    }
    return "Nenhum servidor foi criado ainda";
  }
  return "Você precisa estar logado para remover um servidor";
}

//entra em um servidor
std::string System::enter_server(const std::string name, const std::string code) {
  if (loggedUserId != 0) {
    if (!servers.empty()) {
      bool serverExists = false;

      //procura servidor por nome
      auto server_it = std::find_if(
        servers.begin(), 
        servers.end(), 
        [name](Server server) {
          return isEqual(name, server.getName());
        }
      );

      serverExists = server_it != servers.end();

      //verifica existência do servidor
      if (!serverExists) {
        return "Servidor ‘" + name + "’ não existe";
      }
      
      //procura id do usuário logado na lista de participantes do servidor
      std::vector<size_t> participants = server_it->getPartipants();
      auto participant_it = std::find(
        participants.begin(), 
        participants.end(), 
        loggedUserId
      );

      bool participantExists = participant_it != participants.end();

      if (loggedUserId == server_it->getServerOwnerId() || server_it->getInviteCode() == "") {
        if (!participantExists) {
          server_it->pushParticipantId(loggedUserId);          
        }
        serverNameConnected = name;
        return "Entrou no servidor com sucesso";
      }

      if (server_it->getInviteCode() != "") {
        if (code == "") {
          return "Servidor requer código de convite";
        } else if (isEqual(code, server_it->getInviteCode())) {
          if (!participantExists) {
            server_it->pushParticipantId(loggedUserId);          
          }
          serverNameConnected = name;
          return "Entrou no servidor com sucesso";
        } else {
          return "Código incorreto";
        }
      }
    }
    return "Nenhum servidor foi criado ainda";
  }
  return "Você precisa estar logado para entrar em um servidor";
}

//desconecta do servidor
std::string System::leave_server() {
  if (loggedUserId != 0) {
    if (serverNameConnected != "") {
      std::string tempName = serverNameConnected;
      serverNameConnected = "";

      return "Saindo do servidor ‘" + tempName + "’";
    }
    return "Você não está visualizando nenhum servidor";
  }
  return "Você precisa estar logado para sair de um servidor";
}

//lista participantes do servidor que está sendo visualizado
std::string System::list_participants() {
  if (loggedUserId != 0) {
    if (serverNameConnected != "") {
      std::string serverName = serverNameConnected;
      bool serverExists = false;

      //procura servidor por nome
      auto server_it = std::find_if(
        servers.begin(), 
        servers.end(), 
        [serverName](Server server) {
          return isEqual(serverName, server.getName());
        }
      );

      serverExists = server_it != servers.end();

      if (serverExists) {
        std::vector<size_t> participants = server_it->getPartipants();

        //percorre lista de ids e imprime participantes do servidor
        for (size_t i = 0; i < participants.size(); i++) {
          std::cout << users[i].getName();
          if (i != participants.size() - 1) {
            std::cout << std::endl;
          }
        }

        return "";
      }
      return "Servidor não existe";
    }
    return "Você não está conectado a nenhum servidor";
  }
  return "Você precisa estar logado para visualizar participantes de um servidor";
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