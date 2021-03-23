#ifndef USER_H
#define USER_H

//representa um usuário
class User {
  private:
    size_t id; //id do usuário
    std::string name; //nome do usuário
    std::string email; //email do usuário
    std::string password; //senha do usuário

  public:
    size_t getId();
    void setId(size_t id);

    std::string getName();
    void setName(std::string name);

    std::string getEmail();
    void setEmail(std::string email);

    std::string getPassword();
    void setPassword(std::string password);

    User(); //construtor
    ~User(); //destrutor
};

#endif