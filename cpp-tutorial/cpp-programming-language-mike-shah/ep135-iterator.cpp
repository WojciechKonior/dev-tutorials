#include <iostream>
#include <vector>

void print_vector(std::vector<int>& vec) {
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main(){
    std::vector<int> vec = {1, 2, 3, 4, 5};
    print_vector(vec);
    return 0;
}
