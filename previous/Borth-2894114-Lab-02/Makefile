Program: main.o Executive.o Driver.o LinkedList.o Node.o
	g++ -std=c++11 -g -Wall main.o Executive.o Driver.o LinkedList.o Node.o -o Program

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

Driver.o: Driver.h Driver.cpp
	g++ -std=c++11 -g -Wall -c Driver.cpp

LinkedList.o: LinkedList.h LinkedList.cpp
	g++ -std=c++11 -g -Wall -c LinkedList.cpp

Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Node.cpp

clean:
	rm *.o Program
