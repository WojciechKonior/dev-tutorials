#include <iostream>
#include <utility>

int main() {

    int a = -2;
    unsigned int b = 1;

    if(a>b) std::cout << "Coooo!!!?" << std::endl;
    if(std::cmp_greater(a,b)) std::cout << "Should not print" << std::endl;
    return 0;
}
