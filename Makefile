.DEFAULT_GOAL := all

user.o: user.cpp user.h
	g++ user.cpp -c

system.o: system.cpp system.h user.o
	g++ system.cpp -c

executor.o: executor.cpp executor.h system.o
	g++ executor.cpp -c

objects: system.o executor.o user.o

concordo: objects concordo.cpp
	g++ -Wall system.o executor.o user.o concordo.cpp -o concordo

clean:
	rm *.o concordo

all: concordo

run:
	./concordo

#-fsanitize=address