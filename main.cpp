#include "Vector.hpp"
#include "UnweightedGraphs.hpp"
#include <string>

void test0();

int main(){
    return 0;
}

void test0() {
    UnweightedGraphs<std::string> *ug = new UnweightedGraphs<std::string>();
    std::string str = "a";
    ug->addNode(str);
    std::cout << *ug;
}