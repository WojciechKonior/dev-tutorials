#include <iostream>

constexpr int add(int a, int b) {
    return a+b;
}

int main() {

    int i = 7+9+16;
    constexpr int j = 7+9+16; // better
    constexpr int k = add(7,9); // also works with functions that are constexpr
    std::cout << "Done" << std::endl;
    return 0;
}
