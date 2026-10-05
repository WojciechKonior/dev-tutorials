#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int main(){
    std::string s1 = "apple";
    std::string s2 = "microsoft";
    bool res = std::all_of(s1.begin(), s2.end(), [](char c){return c>0;});
    std::cout << "all of 'apple' characters are greater than 0? : " << (res?"Yes":"No") << std::endl;

    std::vector v1{1, 3, 5, 7};
    res = std::any_of(v1.begin(), v1.end(), [](int i){return i==3;});
    std::cout << "in vector there is one '3' value? : " << (res?"Yes":"No") << std::endl;

    std::vector v2{2, 4, 6, 8};
    res = std::none_of(v2.begin(), v2.end(), [](int i){ return i>7;});
    std::cout << "in vecotor there is none of greater than 7 number? : " << (res?"Yes":"No") << std::endl;
    // res = std::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end());
    // std::cout << "v1 comes before v2? : " << (res?"Yes":"No") << std::endl;
    return 0;
}
