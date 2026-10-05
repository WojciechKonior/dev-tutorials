#include <iostream>
#include <algorithm>
#include <array>

int main(){
    std::array<int, 10> arr = {2, 1, 3, 4, 5, 6, 7, 8, 9, 10};
    std::array<int, 10> arr2 = {2, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto it = std::mismatch(arr.begin()+7, arr.end(), arr2.begin()+7);
    if(it.first != arr.end() && it.second != arr2.end()){
        std::cout << "First mismatch: " << *it.first << " and " << *it.second << std::endl;
    } else {
        std::cout << "No mismatches found." << std::endl;
    }

    auto it2 = std::equal(arr.begin(), arr.end(), arr2.begin());
    if(it2){
        std::cout << "arr and arr2 are equal\n";
    } else {
        std::cout << "arr != arr2\n";
    }

    auto it3 = std::equal(arr.begin()+7,arr.end(), arr2.begin()+7, arr.end(), [](int a, int b){return a==b;});
    if(it3){
        std::cout << "arr[7-9]==arr2[7-9]\n";
    } else {
        std::cout << "arr[7-9]!=arr2[7-9]\n";
    }
    return 0;
}
