#include <iostream>
#include <print>
#include <vector>
#include <ranges>
#include <algorithm>

int main(){
    std::vector<int> vec = {1, 2, 3, 4, 5};
    auto print_lambda = [](auto element){std::print("{} ");};
    std::ranges::for_each(vec, print_lambda);
    std::print("\n");

    return 0;
}
