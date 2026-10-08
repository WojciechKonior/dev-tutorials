#include <iostream>
#include <sstream>
#include <string>

int main(){
    std::stringstream ss("line 1: ");
    ss << "Wojtek Konior" << std::endl;
    std::cout << ss.str() << std::endl;

    return 0;
}
