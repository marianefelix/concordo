#ifndef USER_H
#define USER_H

//representa um usuário
class User {
  private:
    size_t id;
    std::string name;
    std::string email;
    std::string password;

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