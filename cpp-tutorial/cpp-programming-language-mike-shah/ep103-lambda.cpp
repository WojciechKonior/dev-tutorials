#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v{1, 2, 3, 4, 5};
    std::for_each(v.begin(), v.end(), [](int n)->int {std::cout << n << ","; return 0; });
    std::cout << std::endl;
    
    return 0;
}
