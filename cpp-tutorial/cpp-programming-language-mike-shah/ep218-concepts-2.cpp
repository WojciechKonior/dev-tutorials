#include <iostream>
#include <print>
#include <cmath>
#include <concepts>
#include <vector>

template<typename T>
concept SmallDataExpression = sizeof(T)<8;

template<typename T>
concept BigDataExpression = !SmallDataExpression<T>;

template<typename T>
requires SmallDataExpression<T>
void Print(T data){
    std::print("{}\n", data);
}

template<typename T>
requires BigDataExpression<T>
void Print(T data){
    std::cout << "[ ";
    for(auto a : data){
        std::cout << a << " ";
    }
    std::cout << "]\n";
}

int main(){
    int i = 10;
    std::vector<int> v = {1, 2, 3 , 4, 6};

    Print<int>(i);
    Print<std::vector<int>>(v);

    return 0;
}
