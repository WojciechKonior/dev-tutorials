#include <iostream>
#include <vector>
#include <algorithm>

auto PassByValue(std::vector<int> vec) -> void {
    vec[0] = 1;
}

auto PassByReference(std::vector<int>& vec) -> void {
    vec[0] = 1;
}

int main(){ // main function is a main entrypoint
    std::vector<int> v(1000);
    
    std::fill(v.begin(), v.end(), 2);
    
    PassByValue(v);
    std::cout << "v[0] passed by value is " << v[0] << std::endl;
    
    PassByReference(v);
    std::cout << "v[0] passed by reference is " << v[0] << std::endl;

    
    return 0;
}
