#include <iostream>
#include <print>

int main(){
    std::print("Hello World\n");
    std::println("Hello World the second time");

    std::string name = "Wojtek";
    std::string msg = "Hello";
    constexpr auto format1 = "{0} {1}\n";
    constexpr auto format2 = "{1} {0}\n";

    std::print(format1, msg, name);
    std::print(format2, msg, name);

    std::cout << "some cout" << std::endl;
    std::cerr << "some error" << std::endl;
    std::clog << "some log" << std::endl;

    return 0;
}
