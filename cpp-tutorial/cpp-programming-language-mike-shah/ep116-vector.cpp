#include <iostream>
#include <vector>
#include <span>

void PrintVector(std::span<int> vec) {
    for (const auto& element : vec) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

void CStylePrint(int* data, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

int main(){
    std::vector myVector = {1, 2, 3, 4};
    myVector.push_back(6);
    myVector.reserve(20);
    myVector.emplace_back(5);
    myVector.erase(myVector.begin() + 1);
    myVector.shrink_to_fit();

    for(auto& element : myVector){
        std::cout << element << " ";
    }
    std::cout << std::endl << myVector.capacity()<< std::endl;

    PrintVector(myVector);
    CStylePrint(myVector.data(), myVector.size());

    return 0;
}
