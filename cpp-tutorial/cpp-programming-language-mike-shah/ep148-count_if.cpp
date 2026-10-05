#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int main(){
    std::vector v1{1, 3, 5, 7};
    auto res = std::count_if(v1.begin(), v1.end(), [](int i){ return i>3; });
    std::cout << "count: " << res << std::endl;

    res = std::count(v1.begin(), v1.end(), 5);
    std::cout << "count: " << res << std::endl;
    return 0;
}
