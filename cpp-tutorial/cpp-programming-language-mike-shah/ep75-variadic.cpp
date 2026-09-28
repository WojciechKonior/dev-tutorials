#include <iostream>
#include <string>

template<typename T> T Sum(T arg) { return arg; }
template<typename T, typename... Args> T Sum(T arg, Args... args) { return arg+Sum(args...);}

int main() {
    std::cout << Sum<int>(1, 2, 3, 4, 5) << std::endl;
    
    return 0;
}
