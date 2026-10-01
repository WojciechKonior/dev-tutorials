#include <iostream>
#include <set>

int main(){
    std::multiset<int> ms = {1, 2, 3, 4, 5, 5, 6, 7, 8, 9};
    ms.insert(5);
    ms.insert(6);
    ms.insert(4);
    std::cout << "5 occurs " << ms.count(5) << " times in the multiset.\n";
    std::cout << "6 occurs " << ms.count(6) << " times in the multiset.\n";
    std::cout << "4 occurs " << ms.count(4) << " times in the multiset.\n";
    ms.erase(4);
    std::cout << "After erasing 4, it occurs " << ms.count(4) << " times in the multiset.\n";
    std::cout << "Size of the multiset: " << ms.size() << "\n";
    std::cout << "Is empty: " << (ms.empty() ? "Yes":"No") << "\n";
    ms.clear();
    std::cout << "Is empty: " << (ms.empty() ? "Yes":"No") << "\n";
    
    return 0;
}
