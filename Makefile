.DEFAULT_GOAL := all

user.o: user.cpp user.h
	g++ user.cpp -c

server.o: server.cpp server.h
	g++ server.cpp -c

system.o: system.cpp system.h user.o server.o
	g++ system.cpp -c

executor.o: executor.cpp executor.h system.o
	g++ executor.cpp -c

objects: system.o executor.o user.o

concordo: objects concordo.cpp
	g++ -Wall -fsanitize=address system.o executor.o user.o server.o concordo.cpp -o concordo

clean:
	rm *.o concordo

all: concordo

run:
	./concordo

#-fsanitize=address