#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>

int main(){
    std::vector v1{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> v2(20, 0);

    std::generate(v1.begin(), v1.end(), [](){ static int i = 0; return i++;});
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

    return 0;
}
