#include <iostream>
#include <unistd.h>
#include <vector>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};

    for (int* ptr = arr; ptr < arr + 5; ++ptr) {
        std::cout << ptr << "(of size " << sizeof(ptr) << ")" << " : " << *ptr << " (which is of size " << sizeof(*ptr) << ")" << std::endl;
    }

    std::cout << "Size of stack array: " << sizeof(arr) << std::endl;
    
    int* dynamicArr = new int[5]{1, 2, 3, 4, 5};

    std::cout << "Size of dynamic array: " << sizeof(dynamicArr) << std::endl;

    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::cout << "Size of vector: " << sizeof(vec) << std::endl; // only size of data structure, not the elements
    sleep(1);
    return 0;
}
