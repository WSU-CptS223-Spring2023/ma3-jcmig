prog: main.o TwitterData.o
		g++ -g main.o TwitterData.o -o MA3

main.o: main.cpp TwitterData.hpp
		g++ -c -g -Wall -std=c++11 main.cpp 

TwitterData.o: TwitterData.cpp TwitterData.hpp
		g++ -c -g -Wall -std=c++11 TwitterData.cpp

clean:
		-rm *.o

run: @./MA3