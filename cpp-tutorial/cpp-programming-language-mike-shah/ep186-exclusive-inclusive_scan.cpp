#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <execution>

void printContainer(auto sp){
    for(const auto& s : sp){
        std::cout << s << " ";
    }
    std::cout << std::endl;
}

int main(){
    std::vector<int> v(10), v0(10), v1(10), v2, v3;
    std::iota(v.begin(), v.end(), 0);
    std::iota(v1.begin(), v1.end(), 0);
    printContainer(v);

    std::inclusive_scan(v.begin(), v.end(), v1.begin());
    std::exclusive_scan(v.begin(), v.end(), v0.begin(), 0);

    printContainer(v1);
    printContainer(v0);

    return 0;
}
