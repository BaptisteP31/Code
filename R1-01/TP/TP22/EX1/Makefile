main.out: main.o file.o
	g++ -Wall -o main.out main.o file.o

main.o: src/main.cpp
	g++ -Wall -c src/main.cpp

file.o: src/file.cpp
	g++ -Wall -c src/file.cpp

clean:
	rm -rf *.o