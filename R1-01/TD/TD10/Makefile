CXX = g++
CXXFLAGS = -Wall -Werror -pedantic -std=c++17 -g -fsanitize=address
LDFLAGS =  -std=c++17 -fsanitize=address

calc.app: calc.o rpn.o
	$(CXX) $(LDFLAGS) -o calc.app calc.o rpn.o

calc.o:
	$(CXX) $(LDFLAGS) -c src/calc.cpp

rpn.o:
	$(CXX) $(LDFLAGS) -c src/rpn.cpp

clean:
	rm -rf *.o