#include <iostream>
#include <string>

struct API{
    static int some_static;
    static int getStatic(){ return some_static; }
};

int API::some_static = 10;

int main() {
    std::cout << API::some_static << std::endl;
    std::cout << API::getStatic() << std::endl;
    
    return 0;
}
