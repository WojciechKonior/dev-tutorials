#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>
#include <random>

int main(){
    std::vector v1{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> v2(20, 0);

    std::generate(v1.begin(), v1.end(), [](){ static int i = 0; return i++;});
    auto newEnd = std::remove_if(v1.begin(), v1.end(), [](auto i){return i>5;});
    v1.erase(newEnd, v1.end());
    newEnd = std::remove(v1.begin(), v1.end(), 5);
    v1.erase(newEnd, v1.end());
    std::erase(v1, 0);
    std::erase_if(v1, [](int i){return i<2;});

    std::generate_n(v2.begin(), 10, [](){ static int i = 0; return i++;});
    std::reverse(v2.begin(), v2.end());

    std::vector<int> v3;
    std::reverse_copy(v1.begin(), v1.end(), std::back_inserter(v3));

    for(const auto& a: v1){
        std::cout << a << " ";
    }
    std::cout << std::endl;

    for(const auto& a: v2){
        std::cout << a << " ";
    }
    std::cout << std::endl;

    for(const auto& a: v3){
        std::cout << a << " ";
    }
    std::cout << std::endl;

    std::vector<int> v4;
    std::sample(v2.begin(), v2.end(), std::back_inserter(v4), 4, std::mt19937{std::random_device{}()});
    for(const auto& a: v4){
        std::cout << a << " ";
    }
    std::cout << std::endl;

    std::rotate(v2.begin(), v2.begin()+4, v2.end());
    for(const auto& a: v2){
        std::cout << a << " ";
    }
    std::cout << std::endl;

    return 0;
}
