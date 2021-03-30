#ifndef MESSAGE_H
#define MESSAGE_H

//representa uma mensagem
class Message {
  private:
    std::string dateTime; //data e hora da mensagem
    size_t sendBy; //guarda id do usuário que enviou a mensagem
    std::string content; //conteúdo da mensagem
  
  public:
    std::string getDateTime();
    void setDateTime(std::string dateTime);

    size_t getSendBy();
    void setSendBy(size_t sendBy);

    std::string getContent();
    void setContent(std::string content);

    Message(); //construtor
    ~Message(); //destrutor
};

#endif