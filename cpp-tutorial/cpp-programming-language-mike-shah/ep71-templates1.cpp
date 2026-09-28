#include <iostream>
#include <string>

template<typename T> T square(T input){ return input*input; }

template<> int square<int>(int input) { return input*input; } // template int specialization
template<> float square<float>(float input) { return input*input; }
template<> double square<double>(double input) { return input*input; }

int main() {
    std::cout << square(2) << std::endl; // tutaj działa template argument deduction
    std::cout << square<float>(2.2f) << std::endl;
    std::cout << square<float>(2.2f) << std::endl;
    
    return 0;
}
