#include <iostream>
#include <initializer_list>

class UDT {
public:
    UDT(std::initializer_list<int> data): m_data(data) {
        std::cout << "initializer_list<int> constructor\n";
    }
    ~UDT() {}
    void PrintData(){
        for(auto& e : m_data) std::cout << e << " ";
        std::cout << std::endl;
    }

private:
    std::initializer_list<int> m_data;
};

int main() {
    int a = 4.2;
    int b(4.2);
    // int c{4.2}; //error: narrowing conversion

    UDT somedata{1, 2, 3, 4, 5};
    somedata.PrintData();

    return 0;
}
