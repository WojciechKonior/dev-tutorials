#include <print>
#include <unordered_map>
#include <string>
#include <ranges>
#include <vector>
#include <algorithm>
#include <tuple>

int main(){
    std::unordered_map<std::string, std::string> dict = {
        {"cat", "a small animal that says 'meow'"},
        {"dog", "a small animal that says 'bark'"},
        {"cow", "a big animal that says 'moo'"}
    };
    
    for(auto& pair : dict){
        std::print("{} is {}\n", pair.first, pair.second);
    }

    // for(auto& element : dict){
    //     std::println("{}", element);
    // }

    for(auto& [key, value] : dict){
        std::print("{} is {}\n", key, value);
    }
    auto keys_sorted = std::views::keys(dict) | std::ranges::to<std::vector>();
    std::ranges::sort(keys_sorted);

    for(auto& key : keys_sorted){
        std::print("{} is {}\n", key, dict[key]);
    }

    std::vector<std::tuple<std::string, std::string, int>> dict3;

    for(auto& element : dict){
        dict3.push_back({element.first, element.second, 4});
    }

    for(auto& [first, second, third] : dict3){
        std::print("{} is {} and is {} years old\n", first, second, third);
    }

    for(auto& e : std::views::elements<0>(dict3)){
        std::print("{}, ", e);
    }

    std::print("Done\n");
    return 0;
}
