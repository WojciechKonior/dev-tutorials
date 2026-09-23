// main.cpp
#include <iostream>
#include "wojtek.hpp"

int main() {
    std::cout << add(1,2) << std::endl;
    return 0;
}

// wojtek.hpp
#ifndef WOJTEK_HPP
#define WOJTEK_HPP
int add(int a, int b);
#endif

// wojtek.cpp
#include "wojtek.hpp"

int add(int a, int b){
    return a+b;
}


// to run: g++ -std=c++17 -g3 -O0 main.cpp wojtek.cpp -o main; ./main
