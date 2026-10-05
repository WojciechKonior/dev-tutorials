#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int main(){
    std::string s1 = "apple";
    std::string s2 = "microsoft";
    bool res = std::lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end());
    std::cout << "apple comes before microsoft in dictionary? : " << (res?"Yes":"No") << std::endl;

    std::vector v1{1, 3, 5, 7};
    std::vector v2{2, 4, 6, 8};
    res = std::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end());
    std::cout << "v1 comes before v2? : " << (res?"Yes":"No") << std::endl;
    return 0;
}
