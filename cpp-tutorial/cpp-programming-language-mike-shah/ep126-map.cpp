#include <iostream>
#include <utility>
#include <map>

void printMap(const std::map<std::string, int>& myMap) {
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

int main(){
    std::map<std::string, int> myMap;
    myMap["apple"] = 5;
    myMap["banana"] = 3;
    myMap.insert({"orange", 7});
    myMap.insert(std::make_pair("grape", 2));

    printMap(myMap);
    std::cout << myMap.size() << std::endl;
    std::cout << myMap.count("banana") << std::endl;
    std::cout << myMap["apple"] << std::endl;
    std::cout << myMap.at("orange") << std::endl;
    
    return 0;
}
