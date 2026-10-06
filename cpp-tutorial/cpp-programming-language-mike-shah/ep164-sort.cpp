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

    std::sort(v1.begin(), v1.end());
    printContainer(v1);

    std::stable_sort(v2.begin(), v2.end());
    printContainer(v2);

    return 0;
}
