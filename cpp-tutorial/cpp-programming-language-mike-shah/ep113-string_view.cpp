#include <iostream>
#include <string>

void printStr(std::string_view sv){
    std::cout << sv << std::endl;
}

int main() {
    std::string name("Wojtek Konior Wojtek Konior");
    std::string_view sv = name;

    std::cout << sizeof(name) << std::endl;
    std::cout << sizeof(sv) << std::endl;

    return 0;
}
