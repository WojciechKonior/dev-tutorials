#include <iostream>
#include <algorithm>
#include <vector>


void printContainer(auto sp){
    for(const auto& s : sp){
        std::cout << s << " ";
    }
    std::cout << std::endl;
}

int main(){
    std::vector<int> v1{1, 2, 3, 4, 5, 7, 8};
    std::vector<int> v2{8, 2, 4, 6, 1, 3, 5};
    std::vector<int> v3, v4;

    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(v3));
    std::inplace_merge(v3.begin(), v3.begin()+4, v3.end());
    std::sort(v3.begin(), v3.end());
    printContainer(v3);

    std::cout << std::binary_search(v3.begin(), v3.end(), 7) << std::endl;
    std::cout << *std::lower_bound(v3.begin(), v3.end(), 7) << std::endl;
    std::cout << *std::upper_bound(v3.begin(), v3.end(), 7) << std::endl;

    return 0;
}
