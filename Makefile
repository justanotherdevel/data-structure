all: main

main: *.o
	g++ *.o -o main -std=c++14 -g

*.o: *.cpp
	g++ -c *.cpp -std=c++14 -g

.PHONY: clean

clean:
	rm *.o main
