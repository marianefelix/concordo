#ifndef EXECUTOR_H
#define EXECUTOR_H

#include "system.h"
#include <istream>
#include <ostream>
#include <sstream>

//classe que representa o executor do sistema
class Executor {
  private:
    System* system; //ponteiro para sistema
    std::stringstream ss;
    bool logout = false; //valor padrão

  public:
    Executor(System &system); //construtor
    void start(std::istream &in, std::ostream &out);
    std::string line_process(std::string linha);
};

#endif