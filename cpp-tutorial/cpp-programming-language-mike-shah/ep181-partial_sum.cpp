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
    std::vector<int> v(10), v2, v3;
    std::iota(v.begin(), v.end(), 5);
    printContainer(v);

    std::adjacent_difference(v.begin(),v.end(), std::back_inserter(v2));
    printContainer(v2);

    std::partial_sum(v.begin(), v.end(), std::back_inserter(v3));
    printContainer(v3);

    return 0;
}
