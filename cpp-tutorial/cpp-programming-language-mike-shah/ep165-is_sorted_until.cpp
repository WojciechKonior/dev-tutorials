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

    std::sort(v1.begin(), v1.end(), std::greater<>());
    printContainer(v1);

    std::stable_sort(v2.begin(), v2.end(), std::less<>());
    printContainer(v2);

    std::stable_sort(v2.begin(), v2.end(), [](const int& a, const int& b){return a>b;});
    printContainer(v2);

    std::cout << "is v2 sorted? : " << std::is_sorted(v2.begin(), v2.end(), std::greater<>()) << std::endl;
    std::cout << "is v2 sorted until? : " << *(std::is_sorted_until(v2.begin(), v2.end()))<< std::endl;

    return 0;
}
