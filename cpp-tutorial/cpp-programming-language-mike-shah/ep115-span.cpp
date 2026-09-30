#include <iostream>
#include <array>
#include <algorithm>
#include <span>
#include <vector>

void printContainer(const std::span<int>& span){
    std::cout << "container of size " << span.extent << ": ";
    for(auto& elem: span)
        std::cout << elem << ", ";
    std::cout << std::endl;
}

int main() {
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    printContainer(arr);
    
    std::span<int> s = arr;
    std::cout << s.extent << std::endl;

    std::vector<int> vec = {1, 2, 3, 4};
    std::span<int> ss(vec);
    std::cout << ss.extent << std::endl;

    return 0;
}
