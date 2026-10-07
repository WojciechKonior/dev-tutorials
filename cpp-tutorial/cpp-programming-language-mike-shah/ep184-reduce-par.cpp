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
    std::vector<int> v(10), v2, v3;
    std::iota(v.begin(), v.end(), 5);
    printContainer(v);

    std::adjacent_difference(v.begin(),v.end(), std::back_inserter(v2));
    printContainer(v2);

    std::partial_sum(v.begin(), v.end(), std::back_inserter(v3));
    printContainer(v3);

    auto a = std::inner_product(v.begin(), v.end(), v2.begin(), 0);
    std::cout << a << std::endl;

    auto b = std::accumulate(v2.begin(), v2.end(), 0);
    std::cout << b << std::endl;

    auto c = std::reduce(std::execution::par, v2.begin(), v2.end(), 0.0);
    std::cout << c << std::endl;

    return 0;
}
