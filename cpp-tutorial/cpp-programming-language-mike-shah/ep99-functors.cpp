#include <iostream>

struct Value{
    int m_res{0};

    int operator()(int value){
        m_res = value;
        return value;
    }
};

int main() {
    Value v;
    std::cout << v(42) << std::endl;
    
    return 0;
}
