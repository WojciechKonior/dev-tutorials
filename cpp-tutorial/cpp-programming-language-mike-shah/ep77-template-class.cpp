#include <iostream>
#include <string>
#include <initializer_list>

template<typename T, size_t N>
struct StackContainer {
    StackContainer(){
        for(size_t i=0; i<N; i++) {
            data[i] = static_cast<T>(0);
        }
    }
    StackContainer(std::initializer_list<T> list) {
        size_t i=0;
        for(auto& elem : list) {
            if(i<N) {
                data[i] = elem;
                i++;
            } else {
                break;
            }
        }
    }
    void print() const {
        for(size_t i=0; i<N; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
    size_t size() const { return N; }
    T data[N];
};

int main() {
    StackContainer<int, 5> c1;
    c1.print();

    StackContainer<int, 5> c2{1, 2, 3, 4, 5};
    c2.print();
    
    return 0;
}
