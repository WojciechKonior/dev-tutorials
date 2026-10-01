#include <iostream>
#include <vector>

int main(){
    std::vector myVector = {1, 2, 3, 4};
    myVector.push_back(6);
    myVector.reserve(20);
    myVector.emplace_back(5);
    myVector.erase(myVector.begin() + 1);
    myVector.shrink_to_fit();

    for(auto& element : myVector){
        std::cout << element << " ";
    }
    std::cout << std::endl << myVector.capacity()<< std::endl;

    return 0;
}
