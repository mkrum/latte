FLAGS=-std=c++11 
LINKS=-I ../utils -L ../utils

all: test

test: test.cpp dense.o
	g++ $(FLAGS) $^ $(LINKS) -lutils -o test

%.o:%.cpp
	g++ $(FLAGS) -c $^ $(LINKS) -lutils -o $@

clean:
	rm -rf *.o test
