#include <iostream>
#include <algorithm>
#include <array>

int main(){
    std::array<int, 10> arr = {2, 1, 3, 4, 5, 6, 7, 8, 9, 10};
    std::array<int, 10> arr2 = {2, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto it = std::mismatch(arr.begin(), arr.end(), arr2.begin());
    if(it.first != arr.end() && it.second != arr2.end()){
        std::cout << "First mismatch: " << *it.first << " and " << *it.second << std::endl;
    } else {
        std::cout << "No mismatches found." << std::endl;
    }
    return 0;
}
