Program: main.o Executive.o WebBrowser.o Tab.o
	g++ -std=c++11 -g -Wall main.o Executive.o WebBrowser.o Tab.o -o Program

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

WebBrowser.o: WebBrowser.h WebBrowser.cpp
	g++ -std=c++11 -g -Wall -c WebBrowser.cpp

Tab.o: Tab.h Tab.cpp
	g++ -std=c++11 -g -Wall -c Tab.cpp

clean:
	rm *.o Program
