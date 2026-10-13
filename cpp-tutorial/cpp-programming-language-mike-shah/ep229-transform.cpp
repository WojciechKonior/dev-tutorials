#include <iostream>
#include <print>
#include <vector>
#include <ranges>
#include <algorithm>

int main(){
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    auto print_lambda = [](int element){std::print("{} ", element);};
    std::ranges::for_each(vec, [](int element){std::cout << element << " ";});
    std::print("\n");
    std::ranges::sort(vec, std::ranges::greater{});
    std::ranges::for_each(vec, print_lambda);


    auto less_than_4 = [](auto& e){ return e<4; };
    std::cout << std::endl;
    for(auto& elem : vec | std::ranges::views::filter(less_than_4)){
        std::print("{} ", elem);
    }
    std::print("\n");

    auto doubleValue = [](auto e){ return 2*e; };

    for(auto elem : vec | std::ranges::views::transform(doubleValue)){
        std::print("{} ", elem);
    }
    std::cout << std::endl;

    auto lessThan3 = [](auto e){ return e<3; };
    for(auto elem: vec | std::ranges::views::drop_while(lessThan3)){
        std::print("{} ", elem);
    }
    std::cout << std::endl;

    return 0;
}
