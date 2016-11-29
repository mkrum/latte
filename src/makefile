LINK=-I ../include
FLAGS=-std=c++11
main: build install check

build:
	python setup.py build

install:
	python setup.py install 

check:
	python ../example/test.py

matrix: matrix.o
	g++ $(FLAGS) tests/matrix-test.cpp matrix.o -o mat $(LINK)  

matrix.o: model/matrix.cpp
	g++ $(FLAGS) model/matrix.cpp $(LINK) -c 

clean: 
	rm -rf mat build/ *.o
