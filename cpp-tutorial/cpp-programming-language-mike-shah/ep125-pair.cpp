#include <iostream>
#include <utility>

int main(){
    std::pair<int, std::string> myPair(42, "Hello");
    auto [myInt, myString] = std::make_pair(42, "Hello");

    std::cout << "myInt: " << myInt << ", myString: " << myString << std::endl;
    std::cout << "myPair.first: " << myPair.first << ", myPair.second: " << myPair.second << std::endl;
    
    return 0;
}
