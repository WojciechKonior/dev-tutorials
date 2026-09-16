#include <iostream>

int main(){ // main function is a main entrypoint
    
    int x = 40;
    float y = 33;
    char a = 'A';
    signed char b = 'B';
    unsigned char c = 'C';
    
    std::cout << "x: " << &x << std::endl;
    std::cout << "y: " << &y << std::endl;
    std::cout << "a: " << (void*)&a << std::endl;
    std::cout << "b: " << (void*)&b << std::endl;
    std::cout << "c: " << (void*)&c << std::endl;
    std::cout << "main: " << (void*)&main << std::endl;
    
    return 0;
}
