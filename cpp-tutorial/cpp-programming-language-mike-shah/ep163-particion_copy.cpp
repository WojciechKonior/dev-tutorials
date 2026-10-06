#include <iostream>
#include <algorithm>
#include <vector>


void printContainer(auto sp){
    for(const auto& s : sp){
        std::cout << s << " ";
    }
    std::cout << std::endl;
}

int main(){
    std::vector<int> v1{1, 2, 3, 4, 5, 7, 8};
    std::vector<int> v2{8, 2, 4, 6, 1, 3, 5};

    std::cout << "is v1 partitioned? : " << std::is_partitioned(v1.begin(), v1.end(), [](int i){return i<5;}) << std::endl;
    std::cout << "is v2 partitioned? : " << std::is_partitioned(v2.begin(), v2.end(), [](int i){return i<5;}) << std::endl;

    std::partition(v2.begin(), v2.end(), [](int i){return i>5;});
    std::cout << "is v2 partitioned? : " << std::is_partitioned(v2.begin(), v2.end(), [](int i){return i<5;}) << std::endl;
    auto it = std::partition_point(v2.begin(), v2.end(), [](int i){return i<5;});
    std::cout << *it << std::endl;
    printContainer(v2);

    std::vector<int> v3(7);
    std::partition_copy(v2.begin(), v2.end(), v3.begin(), v3.end(), [](int i){return i<5;});
    printContainer(v3);

    return 0;
}
