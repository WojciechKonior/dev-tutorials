#include <iostream>
#include <algorithm>
#include <array>

int main(){
    std::array<int, 10> arr = {2, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto it = std::find(arr.begin(), arr.end(), 5);
    if(it != arr.end()){
        std::cout << "Found: " << *it << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }

    auto it2 = std::find_if(arr.begin(), arr.end(), [](int x){return x > 5;});
    if(it2 != arr.end()){
        std::cout << "Found greater than 5: " << *it2 << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }

    std::array<int, 3> seq = {4, 5, 6};
    auto it3 = std::search(arr.begin(), arr.end(), std::begin(seq), std::end(seq));
    if(it3 != arr.end()){
        std::cout << "Found sequence: " << *it3 << std::endl;
    } else {
        std::cout << "Sequence not found" << std::endl;
    }

    auto it4 = std::adjacent_find(arr.begin(), arr.end());
    if(it4 != arr.end()){
        std::cout << "Found adjacent: " << *it4 << std::endl;
    } else {
        std::cout << "No adjacent elements found" << std::endl;
    }
    return 0;
}
