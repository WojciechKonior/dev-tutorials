#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

void printContainer(auto sp){
    for(const auto& s : sp){
        std::cout << s << " ";
    }
    std::cout << std::endl;
}

int main(){
    auto p = std::midpoint(1.1,3.1);
    auto p2 = std::midpoint(3.0f,6.0f);
    auto p3= std::midpoint(5,7);

    std::cout << p << std::endl;
    std::cout << p2 << std::endl;
    std::cout << p3 << std::endl;

    return 0;
}
