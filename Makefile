file.out: vector.o unweightedgraphs.o main.o
	g++ vector.o unweightedgraphs.o main.o -o file.out
vector.o: vector.hpp
	g++ -c --std=c++11 vector.hpp -o vector.o
unweightedgraphs.o: UnweightedGraphs.hpp
	g++ -c --std=c++11 UnweightedGraphs.hpp -o unweightedgraphs.o
main.o: main.cpp
	g++ -c --std=c++11 main.cpp -o main.o