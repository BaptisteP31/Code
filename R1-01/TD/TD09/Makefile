FLAGS=-Wall -std=c++23

main.app : main.o files.o
	g++ $(FLAGS) -o main.app main.o files.o

main.o : src/main.cpp
	g++ $(FLAGS) -c src/main.cpp

files.o : src/files.cpp
	g++ $(FLAGS) -c src/files.cpp

clean :
	rm -rf *.o