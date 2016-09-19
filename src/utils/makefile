FLAGS=-std=c++11

all: libutils.a

test: test.cpp matrix.o activations.o
	g++ $(FLAGS)  $^ -o test

libutils.a: matrix.o activations.o
	ar rcs $@ $^

%.o: %.cpp
	g++ $(FLAGS) -c $^ -o $@

clean:
	rm -rf *.o libutils.a
