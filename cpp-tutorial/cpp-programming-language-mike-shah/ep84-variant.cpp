#include <iostream>
#include <variant>


int main() {
    std::variant<int, float, double> v;
    v = 42;
    std::cout << std::get<int>(v) << std::endl << sizeof(v) << std::endl;
    std::cout << sizeof(std::string("42")) << std::endl;
    if(auto attempt = std::get_if<int>(&v)){
        std::cout << "int: " << *attempt << std::endl;
    } else if(auto attempt = std::get_if<float>(&v)){
        std::cout << "float: " << *attempt << std::endl;
    } else if(auto attempt = std::get_if<double>(&v)){
        std::cout << "double: " << *attempt << std::endl;
    }
    
    std::cout << "Done" << std::endl;
    return 0;
}
