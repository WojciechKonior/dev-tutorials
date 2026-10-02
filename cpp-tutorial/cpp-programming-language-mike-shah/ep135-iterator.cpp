#include <iostream>
#include <vector>
#include <iterator>
#include <unordered_map>

void print_vector(std::vector<int>& vec) {
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it = std::next(it)) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void print_map(std::unordered_map<int, std::string>& map) {
    for (std::unordered_map<int, std::string>::iterator it = map.begin(); it != map.end(); it = std::next(it)) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    }
}

int main(){
    std::vector<int> vec = {1, 2, 3, 4, 5};
    print_vector(vec);
    std::cout << std::distance(vec.begin(), vec.end()) << std::endl;
    std::cout << *(vec.begin()+2) << std::endl;

    std::unordered_map<int, std::string> map = {{1, "one"}, {2, "two"}, {3, "three"}};
    print_map(map);
    return 0;
}
