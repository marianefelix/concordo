.DEFAULT_GOAL := all

objects/user.o: src/user.cpp headers/user.h
		g++ src/user.cpp -Iheaders -Wall -ansi -pedantic -std=c++11 -g -c -o objects/user.o

objects/server.o: src/server.cpp headers/server.h
		g++ src/server.cpp -Iheaders -Wall -ansi -pedantic -std=c++11 -g -c -o objects/server.o

objects/system.o: src/system.cpp headers/system.h objects/user.o objects/server.o
		g++ src/system.cpp -Iheaders -Wall -ansi -pedantic -std=c++11 -g -c -o objects/system.o

objects/executor.o: src/executor.cpp headers/executor.h objects/system.o
		g++ src/executor.cpp -Iheaders -Wall -ansi -pedantic -std=c++11 -g -c -o objects/executor.o

objects/concordo.o: src/concordo.cpp objects/system.o objects/executor.o objects/user.o objects/server.o
		g++ src/concordo.cpp -Iheaders -Wall -ansi -pedantic -std=c++11 -g -c -o objects/concordo.o

concordo: objects/concordo.o objects/system.o objects/executor.o objects/user.o objects/server.o
		g++ objects/*.o -Iheaders -Wall -ansi -pedantic -std=c++11 -g -o concordo

#cria a pasta objects
create_objects:
		mkdir -p objects

all: create_objects concordo

run:
		./concordo

#remove a pasta objects e o executável do projeto
clean:
		rm -rf objects concordo