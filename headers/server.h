#ifndef SERVER_H
#define SERVER_H

//representa um servidor
class Server {
  private:
    size_t serverOwnerId; //id do dono do servidor (quem criou)
    std::string name; //nome do servidor
    std::string description; //descrição do servidor
    std::string inviteCode; //código para entrar no servidor
    std::vector<size_t> participantsIds; //vetor de IDs de usuários que estão no servidor

  public:
    std::string getName();
    void setName(std::string name);

    size_t getServerOwnerId();
    void setServerOwnerId(size_t id);

    std::string getDescription();
    void setDescription(const std::string description);

    std::string getInviteCode();
    void setInviteCode(const std::string code);

    std::vector<size_t> getPartipants();
    void pushParticipantId(size_t id);

    Server(); //construtor
    ~Server(); //destrutor
};

#endif