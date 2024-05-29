all: P3q
P3q: main.o utility.o
	g++ -o P3q main.o utility.o
main.o: main.cpp
	g++ -c -g main.cpp
utility.o: utility.cpp
	g++ -c -g utility.cpp