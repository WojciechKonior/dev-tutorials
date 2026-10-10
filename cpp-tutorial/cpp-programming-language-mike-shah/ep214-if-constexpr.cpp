#include <iostream>
#include <print>
#include <cmath>

template<typename T1, typename T2> bool TestEquality(T1 a, T2 b){
    if constexpr(std::is_floating_point_v<T1> && std::is_floating_point_v<T2>){
        std::cout << "from template <float,float>: ";
        return std::fabs(a-b) < 0.0001f;
    }
    std::cout << "from template: ";
    return a==b;
}

// specialization
template<> bool TestEquality(float a, float b){
    std::cout << "from specialization: ";
    return a==b;
}

int main(){
    std::cout << std::boolalpha;
    std::cout << TestEquality(1, 2) << std::endl;
    std::cout << TestEquality(2, 2) << std::endl;
    std::cout << TestEquality(1.0f, 2.0f) << std::endl;
    std::cout << TestEquality(1.0, 1.0) << std::endl;

    return 0;
}
