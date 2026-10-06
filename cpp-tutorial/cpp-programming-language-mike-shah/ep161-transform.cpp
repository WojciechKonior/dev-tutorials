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
    std::vector<int> v{1, 2, 3, 4, 5, 7, 8};
    std::vector<int> res;
    std::transform(v.begin(), v.end(), std::back_inserter(res), [](int i){ return i*2;});
    printContainer(v);
    printContainer(res);
    return 0;
}
