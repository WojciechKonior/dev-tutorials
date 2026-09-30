#include <iostream>
#include <array>
#include <algorithm>

int main() {
    std::array<int, 5> arr = {1, 2, 3, 4, 5};

    std::cout << arr.size() << std::endl;
    std::cout << sizeof(arr) << std::endl;
    arr.fill(0);
    std::cout << arr.at(3) << std::endl;
    std::cout << arr.max_size() << std::endl;
    std::sort(arr.begin(), arr.end());
    for(const auto& elem: arr)
        std::cout << elem << ", ";
    std::cout << std::endl;

    return 0;
}
