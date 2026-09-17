#include <iostream>
#include <vector>
#include <algorithm>
#include <type_traits>

auto PassByValue(std::vector<int> vec) -> void {
    vec[0] = 1;
}

auto PassByReference(std::vector<int>& vec) -> void {
    vec[0] = 1;
}

auto PassByReference2(const std::vector<int>& vec) -> void {
    const int x = 20;
    std::cout << "v[0] from PassByReference2 is " << vec[0] << std::endl;
    std::cout << "vec is const? " << std::is_const<decltype(x)>::value << std::endl;
}

int main(){ // main function is a main entrypoint
    std::vector<int> v(1000);
    
    std::fill(v.begin(), v.end(), 2);
    
    PassByValue(v);
    std::cout << "v[0] passed by value is " << v[0] << std::endl;
    
    PassByReference(v);
    std::cout << "v[0] passed by reference is " << v[0] << std::endl;

    PassByReference2(v);
    
    return 0;
}
