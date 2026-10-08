#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void printCont(auto cont){
    for(auto e : cont){
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

int main(){

    int a = 10;
    int b = 20;

    std::swap(a, b);

    std::cout << a << " " << b << std::endl;


    std::vector<int> v1{1, 2, 3, 4, 5};
    std::vector<int> v2{5, 6, 7, 8, 9};
    std::swap(v1,v2);
    std::iter_swap(v1.data(), v2.data());

    printCont(v1);
    printCont(v2);

    return 0;
}
