#include <iostream>
#include <unordered_set>

int main(){
    std::unordered_set<int> mySet = {1, 2, 3, 4, 5};
    mySet.reserve(20);
    mySet.insert(6);
    if(mySet.contains(3)){
        std::cout << "Set contains 3\n";
    } else {
        std::cout << "Set does not contain 3\n";
    }
    std::cout << "Bucket count: " << mySet.bucket_count() << std::endl;
    std::cout << "Load factor: " << mySet.load_factor() << std::endl;

    for(int i = 0; i<mySet.bucket_count(); i++){
        std::cout << mySet.bucket_size(i) << " elements in bucket " << i << std::endl;
    }
    
    return 0;
}
