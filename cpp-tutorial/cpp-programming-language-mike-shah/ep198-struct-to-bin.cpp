#include <iostream>
#include <fstream>
#include <vector>
#include <print>

void printContainer(auto data) {
    for(const auto& e : data){
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

void printPointVec(auto data){
    std::print("[ ");
    for(const auto& e : data){
        std::print("[{} {}] ", e.x, e.y);
    }
    std::print("]\n");
}

struct Point{
    int x;
    int y;
};

int main(){
    std::vector<int> a = {1, 2, 3, 4, 5};
    std::vector<int> b(5);

    std::vector<Point> v1 = {{1, 2},{3, 4},{5, 6}};
    std::vector<Point> v2(3);
    
    // printContainer(a);
    printPointVec(v1);
    std::cout << sizeof(v1);

    std::ofstream myfile("data.bin");
    myfile.write(reinterpret_cast<char*>(v1.data()), sizeof(v1));
    myfile.close();

    std::ifstream out("data.bin");
    out.read(reinterpret_cast<char*>(v2.data()), sizeof(v2));
    out.close();

    printPointVec(v2);

    return 0;
}
