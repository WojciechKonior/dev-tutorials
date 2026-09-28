#include <iostream>
#include <string>

template<typename T, typename S> T square(S input){ return input*input; }
template<typename T, size_t N> T mult(T input) { return input*N; }

int main() {
    std::cout << square<float, float>(2) << std::endl; // tutaj działa template argument deduction
    std::cout << square<long, float>(2.2f) << std::endl;
    std::cout << square<int, float>(2.2f) << std::endl;
    std::cout << mult<int, 10>(10) << std::endl;
    
    return 0;
}
