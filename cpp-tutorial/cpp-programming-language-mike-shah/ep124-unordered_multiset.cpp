#include <iostream>
#include <unordered_set>

int main(){
    std::unordered_multiset<int> myset = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    myset.insert(5);

    std::cout << myset.count(5) << " elementów o wartości 5 w zbiorze.\n";
    std::cout << myset.count(11) << " elementów o wartości 11 w zbiorze.\n";
    std::cout << myset.bucket_count() << " kubełków w zbiorze.\n";

    for (int i = 0 ; i < myset.bucket_count(); ++i){
        std::cout << "Kubełek " << i << " zawiera: " << myset.bucket_size(i) << " elementów.\n";
    }
    
    return 0;
}
