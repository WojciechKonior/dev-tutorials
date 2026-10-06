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
    std::vector<int> s1{1, 2, 7, 6, 8, 3, 4, 5};
    std::vector<int> s2{4, 5, 6, 7, 8};
    std::vector<int> s3, s4, s5, s6;

    std::make_heap(s1.begin(), s1.end());
    printContainer(s1);

    std::pop_heap(s1.begin(), s1.end());
    s1.pop_back();
    printContainer(s1);

    std::sort_heap(s1.begin(), s1.end());
    printContainer(s1);

    return 0;
}
