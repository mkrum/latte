LINK=-I ../include
FLAGS=-std=c++11

main: build user

build:
	CC=g++ python setup.py build

install:
	CC=g++ python setup.py install 

user:
	CC=g++ python setup.py install --user

test: test-output test-time

test-output: build user
	@echo Testing output...
	@python ../example/test.py

test-time: build user measure
	@echo Testing time...
	@./tests/measure ../example/test.py | tail -n 1 | awk '{ if ($$1 > 1.0) { print "Time limit exceeded"; exit 1} }'

measure:
	@g++ -o ./tests/measure ./tests/measure.cpp

matrix: matrix.o
	g++ $(FLAGS) tests/matrix-test.cpp matrix.o -o mat $(LINK)  

matrix.o: model/matrix.cpp
	g++ $(FLAGS) model/matrix.cpp $(LINK) -c 

clean: 
	rm -rf mat ./tests/measure build/ *.o
