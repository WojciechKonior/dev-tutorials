#include <iostream>
#include <set>

void printSet(const std::set<int>& s) {
    std::cout << "Zawartość zbioru: ";
    for (const auto& elem : s) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main(){
    std::set<int> mySet = {1, 2, 3, 4, 5};

    mySet.insert(3);
    mySet.insert(6);
    mySet.insert(-1);

    auto found = mySet.find(2);
    if (found != mySet.end()) {
        std::cout << "Znaleziono element: " << *found << std::endl;
    } else {
        std::cout << "Nie znaleziono elementu." << std::endl;
    }

    mySet.erase(4);
    std::cout << "4? : " << (mySet.count(4) ? "Tak" : "Nie") << std::endl;
    std::cout << "5? : " << (mySet.count(5) ? "Tak" : "Nie") << std::endl;

    std::set<int> anotherSet = {5, 6, 7, 8};
    mySet.merge(anotherSet);
    printSet(mySet);
    printSet(anotherSet);
    
    return 0;
}
