#include <iostream>

class Dog {
public:
    float weight, age;

    void Bark(){ std::cout << "Hau Hau" << std::endl; }
    void Walk() {}
};

class Labrador : public Dog {
public:
    int color;
};

int main() {
    
    Labrador l;
    l.Bark();

    std::cout << "sizeof(Dog): " << sizeof(Dog) << std::endl;
    std::cout << "sizeof(Labrador): " << sizeof(Labrador) << std::endl;
    

    return 0;
}
