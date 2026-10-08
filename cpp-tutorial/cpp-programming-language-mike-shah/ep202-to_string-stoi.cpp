#include <iostream>
#include <sstream>
#include <string>

int main(){
    int i = 200;
    std::string s = std::to_string(i);
    int b = std::stoi(s);

    std::cout << b << std::endl;

    return 0;
}
