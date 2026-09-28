#include <iostream>
#include <string>

template<typename T> T square(T input){ return input*input; }
auto square2(auto input) { return input*input; } // only viable with c++20

int main() {
    std::cout << square(2) << std::endl; // tutaj działa template argument deduction
    std::cout << square<float>(2.2f) << std::endl;
    std::cout << square<float>(2.2f) << std::endl;
    std::cout << square2(2.3) << std::endl;
    
    return 0;
}
