#include <iostream>
#include <list>
#include <vector>
#include <string>

#include "system.h"
#include "executor.h"

using std::cout;
using std::cin;

int main() {
  System system;
  Executor executor(system);

  //inicializa sistema
  executor.start(cin, cout);

  return 0;
}