#include <iostream>
#include <string>

int main() {
    std::string name("Wojtek");
    name.shrink_to_fit();

    std::cout << name.data() << std::endl;
    std::cout << name.size() << std::endl;
    std::cout << name.capacity() << std::endl;
    std::cout << name.find('j') << std::endl;

    if(name.find('K') == std::string::npos){
        std::cout << "There is no such in string" << std::endl;
    }

    return 0;
}
