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
    std::pair<int, int> p = std::minmax(7,2);
    std::pair<int, int> p2 = std::minmax({1, 2, 3, 4, 5, 6, 7});

    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    auto [pmin, pmax] = std::minmax({1, 2, 3, 4, 5, 6, 7});

    std::cout << p.first << " " << p.second << std::endl;
    std::cout << p2.first << " " << p2.second << std::endl;
    std::cout << pmin << " " << pmax << std::endl;

    return 0;
}
