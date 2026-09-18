#include <iostream>
#include <unistd.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};

    for (int* ptr = arr; ptr < arr + 5; ++ptr) {
        std::cout << ptr << " : " << *ptr << std::endl;
    }
    sleep(1);
    return 0;
}
