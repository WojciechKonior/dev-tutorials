#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

void printContainer(auto sp){
    for(const auto& s : sp){
        std::cout << s << " ";
    }
    std::cout << std::endl;
}

int main(){
    auto p = std::lerp(1.1,3.1,1);
    auto p2 = std::lerp(3.0f,6.0f,1);
    auto p3= std::lerp(5,7,1);

    std::cout << p << std::endl;
    std::cout << p2 << std::endl;
    std::cout << p3 << std::endl;

    return 0;
}
