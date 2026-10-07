#include <iostream>
#include <format>
#include <string>

void printContainer(auto sp){
    for(const auto& s : sp){
        std::cout << s << " ";
    }
    std::cout << std::endl;
}

int main(){
    std::cout << std::format("Hi, my name is {}.\n", "Wojtek") << std::endl;

    int month = 6, year = 2026;
    constexpr const char* myFormat = "It is now {0}-{1}\n";
    std::cout << std::format(myFormat, month, year) << std::endl;

    return 0;
}
