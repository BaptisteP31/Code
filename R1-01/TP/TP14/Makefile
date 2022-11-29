FLAGS=-Wall -std=c++23

main.app : main.o convert.o
	g++ $(FLAGS) -o main.app main.o convert.o

main.o : main.cpp
	g++ $(FLAGS) -c main.cpp

convert.o : convert.cpp
	g++ $(FLAGS) -c convert.cpp

clean :
	rm -rf *.o