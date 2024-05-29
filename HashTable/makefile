all: hash
hash: main.o Hash_table.o utility.o 
	g++ -o hash main.o Hash_table.o utility.o
main.o: main.cpp
	g++ -c -g main.cpp
Hash_table.o: Hash_table.cpp
	g++ -c -g Hash_table.cpp
utility.o: utility.cpp
	g++ -c -g utility.cpp