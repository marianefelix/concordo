#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include <iostream>
#include "user.h"
//#include <string>


//representa o sistema que concentra todas as operações do Concordo
class System {
  private:
    //precisa guardar uma coleção de servidores;
    std::vector<User> users; //vetor que contém todos os usuários do sistema
    int loggedUserId = 0; //se 0: não logado, caso contrário guarda o id do usuário logado
    std::string serverNameConnected;
    std::string channelNameConneted;

  public:
    std::string quit();
    std::string create_user (const std::string email, const std::string password, const std::string name);
    std::string login(const std::string email, const std::string password);
    std::string disconnect();
    std::string create_server(const std::string name);
    std::string set_server_desc(const std::string name, const std::string description);
    std::string set_server_invite_code(const std::string name, const std::string code);
    std::string list_servers();
    std::string remove_server(const std::string name);
    std::string enter_server(const std::string name, const std::string code);
    std::string leave_server();
    std::string list_participants();
    std::string list_channels();
    std::string create_channel(const std::string name, const std::string type);
    std::string enter_channel(const std::string name);
    std::string leave_channel();
    std::string send_message(const std::string message);
    std::string list_messages();
};

#endif