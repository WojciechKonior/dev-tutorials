#include <iostream>
#include <utility>
#include <unordered_map>

void printMap(const std::unordered_multimap<std::string, int>& myMap) {
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

int main(){
    std::unordered_multimap<std::string, int> myMap;
    myMap.insert({"apple", 5});
    myMap.insert({"banana", 3});
    myMap.insert({"apple", 10});
    myMap.insert({"banana", 1});
    myMap.insert({"orange", 7});
    myMap.insert(std::make_pair("grape", 2));
    myMap.insert(std::make_pair("banana", 4));
    myMap.erase("orange");
    auto itr = myMap.find("banana");
    myMap.erase(itr);

    printMap(myMap);
    std::cout << myMap.size() << std::endl;
    std::cout << myMap.count("banana") << std::endl;
    std::cout << myMap.count("apple") << std::endl;
    std::cout << myMap.size() << std::endl;
    std::cout << myMap.bucket_size(myMap.bucket("banana")) << std::endl;
    std::cout << myMap.bucket_count() << std::endl;

    
    return 0;
}
