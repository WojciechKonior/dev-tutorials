#include <iostream>
#include <algorithm>
#include <vector>
#include <initializer_list>

void printContainer(auto sp){
    for(const auto& s : sp){
        std::cout << s << " ";
    }
    std::cout << std::endl;
}

int main(){
    std::vector<int> s1{1, 2, 7, 6, 8, 3, 4, 5};
    std::vector<int> s2{4, 5, 6, 7, 8};
    std::vector<int> s3, s4, s5, s6;

    std::make_heap(s1.begin(), s1.end());
    printContainer(s1);

    std::cout << std::max({1, 2, 3, 4, 5}) << std::endl;
    std::cout << std::min({1, 2, 3, 4, 5}) << std::endl;

    std::cout << *std::max_element(s1.begin(), s1.end()) << std::endl;
    std::cout << *std::min_element(s1.begin(), s1.end()) << std::endl;

    return 0;
}
