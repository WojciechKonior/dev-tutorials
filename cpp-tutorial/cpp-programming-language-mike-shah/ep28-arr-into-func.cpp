#include <iostream>
#include <array>
#include <vector>

void printArray(int arr[], int size) {
    std::cout << "Array elements: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void printStdArray(std::array<int, 6> arr) {
    std::cout << "std::array elements: ";
    for (const auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void printVector(const std::vector<int>& vec) {
    std::cout << "std::vector elements: ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    printArray(arr, 5);

    std::array<int, 6> stdArr = {6, 7, 8, 9, 10};
    printStdArray(stdArr);

    std::vector<int> vec = {11, 12, 13, 14, 15};
    printVector(vec);
    
    return 0;
}
