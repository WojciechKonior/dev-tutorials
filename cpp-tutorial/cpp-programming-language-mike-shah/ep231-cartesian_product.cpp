#include <print>
#include <ranges>
#include <vector>
#include <string>

int main(){

    std::vector<std::string> names = {"Wotek", "Kuba", "Monika"};
    std::vector<int> health = {10, 20, 30};
    std::vector<int> magic = {100, 200, 300};

    auto all_combined = std::views::cartesian_product(names, health, magic) | std::views::take(5);

    for(auto const& [name, health, magic] : all_combined){
        std::println("(name={} health={} magic={}", name, health, magic);
    }
    
    std::print("Done\n");
    return 0;
}
