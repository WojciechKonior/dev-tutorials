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

    std::cout.write("Hello World\n",12);
    std::cout.put('H');
    std::cout.put('e');
    std::cout.put('l');
    std::cout.put('l');
    std::cout.put('o');
    std::cout.put(' ');
    std::cout.put('W');
    std::cout.put('o');
    std::cout.put('r');
    std::cout.put('l');
    std::cout.put('d');
    std::cout.put('\n');

    std::cout << std::hex << 12 << std::endl << std::oct << 12 << std::endl << std::dec << 12 << std::endl; 

    int a, b, c;
    std::cin>>a>>b>>c;
    std::cout << a << std::endl << b << std::endl << c << std::endl;
    return 0;
}
