#include <iostream>
#include <print>
#include <cmath>
#include <concepts>
#include <vector>

template<typename T>
concept IsSmallAllocation = requires(T container){
    container.size() < 4;
};

template<typename T>
requires IsSmallAllocation<T>
void Print(T c){
    std::cout << "[ ";
    for (const auto& e : c){
        std::cout << e << " ";
    }
    std::cout << "]\n";
}

int main(){
    std::vector<int> vec = {1, 2, 3, 3, 4};
    Print<std::vector<int>>(vec);

    return 0;
}
