#include <iostream>

int main() {
    std::string myString = "copy construct me";
    std::string newValue, newValue2;

    std::cout << "myString: " << myString << std::endl;
    std::cout << "newValue: " << newValue << std::endl;
    std::cout << "newValue2: " << newValue2 << std::endl;

    newValue = static_cast<std::string&&>(myString);
    std::cout << "\nAfter staticaly cast to rvalue reference: " << std::endl;

    std::cout << "myString: " << myString << std::endl;
    std::cout << "newValue: " << newValue << std::endl;
    std::cout << "newValue2: " << newValue2 << std::endl;

    newValue2 = std::move(newValue);
    std::cout << "\nAfter std::move: " << std::endl;

    std::cout << "myString: " << myString << std::endl;
    std::cout << "newValue: " << newValue << std::endl;
    std::cout << "newValue2: " << newValue2 << std::endl;

    return 0;
}
