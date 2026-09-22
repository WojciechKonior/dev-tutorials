#include <iostream>
#include <memory>

class SomeClass{
public:
    SomeClass() { std::cout << "SomeClass created" << std::endl; }
    ~SomeClass() { std::cout << "SomeClass destroyed" << std::endl; }
};

typedef int (*fcn_ptr)(int, int);

int main() {
    std::unique_ptr<SomeClass> ptr = std::unique_ptr<SomeClass>(new SomeClass());
    std::unique_ptr<SomeClass[]> arr = std::unique_ptr<SomeClass[]>(new SomeClass[10]);

    auto ptr2 = std::move(ptr);


    return 0;
}
