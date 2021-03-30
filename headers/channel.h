#ifndef CHANNEL_H
#define CHANNEL_H

//representa um canal
class Channel {
  private:
    std::string name; //nome do canal
  
  public:
    std::string getName();
    void setName(std::string name);

    Channel(); //construtor
    ~Channel(); //destrutor
};

#endif