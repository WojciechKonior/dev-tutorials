#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>

int main(){
    std::vector v1{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> v2;
    std::copy_if(v1.begin(), v1.end(), std::back_inserter(v2), [](int i){return i%2==0;});

    for(auto a: v2){
        std::cout << a << " ";
    }
    std::cout << std::endl;

    std::vector<int> v3;
    std::copy_n(v1.begin()+2, v1.size()-2, std::back_inserter(v3));

    return 0;
}
