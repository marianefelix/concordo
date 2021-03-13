#ifndef USER_H
#define USER_H

//classe que representa um usuário
class User {
  private:
    size_t id;
    std::string name;
    std::string email;
    std::string password;

  public:
    std::string getEmail();
    std::string getPassword();
    size_t getId();

    User(size_t id, std::string name, std::string email, std::string password); //construtor
    ~User(); //destrutor
};

#endif