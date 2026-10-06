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
    std::vector<int> s1{1, 2, 3, 4, 5};
    std::vector<int> s2{4, 5, 6, 7, 8};
    std::vector<int> s3, s4;

    std::set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), std::back_inserter(s3));
    std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), std::back_inserter(s4));

    printContainer(s3);
    printContainer(s4);

    return 0;
}
