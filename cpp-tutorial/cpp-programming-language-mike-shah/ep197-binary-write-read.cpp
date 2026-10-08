#include <iostream>
#include <fstream>
#include <vector>

void printContainer(auto data) {
    for(const auto& e : data){
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

int main(){
    std::vector<int> a = {1, 2, 3, 4, 5};
    std::vector<int> b(5);
    
    printContainer(a);

    std::ofstream myfile("data.bin");
    myfile.write(reinterpret_cast<char*>(a.data()), a.size()*sizeof(int));
    myfile.close();

    std::ifstream out("data.bin");
    out.read(reinterpret_cast<char*>(b.data()), b.size()*sizeof(int));
    out.close();

    printContainer(b);

    return 0;
}
