#include <iostream>
#include <string>
#include <vector>

class Arr{
public:
    Arr(): size(0), data(nullptr) { std::cout << "default constructor" << std::endl; }
    Arr(int s): size(s), data(new int[s]) { std::cout << "constructor" << std::endl; }
    Arr(const Arr& a){
        if(&a!=this){
            size = a.size;
            data = new int[size];
            for(int i = 0; i<size; i++) 
                data[i] = a.data[i];
        }
        std::cout << "copy constructor" << std::endl;
    }
    Arr& operator=(const Arr& a){
        if(&a!=this){
            size = a.size;
            if(data!=nullptr) delete[] data;
            data = new int[size];
            for(int i = 0; i<size; i++) 
                data[i] = a.data[i];
        }
        std::cout << "copy-assignment operator" << std::endl; 
        return *this;       
    }
    Arr(Arr&& a){
        if(&a!=this){
            size = a.size;
            data = a.data;
            a.data = nullptr;
            a.size = 0;
        }
        std::cout << "move constructor" << std::endl;       
    }
    Arr& operator=(Arr&& a){
        if(&a!=this){
            size = a.size;
            data = a.data;
            a.size = 0;
            a.data = nullptr;
        }
        std::cout << "move-assignment operator" << std::endl; 
        return *this;         
    }
    ~Arr(){ 
        std::cout << "destructor" << data << std::endl; 
        if(nullptr != data) 
            delete[] data; 
    }
    void populate(){ for(int i = 0; i<size; i++) data[i] = i; }

public:
    int size;
    int *data;
};

std::ostream& operator<<(std::ostream& os, const Arr& arr){
    if(arr.size == 0) 
        os << "empty";
    for(int i = 0; i<arr.size; i++)
        os << arr.data[i] << " ";
    return os;
}

int main() {
    Arr a(10);
    a.populate();
    std::cout << "a: " << a << std::endl;

    Arr b(a);
    std::cout << "b: " << b << std::endl;

    Arr c;
    c = a;
    c = b;
    std::cout << "c: " << c << std::endl;

    Arr d(std::move(a));
    std::cout << "d: " << d << std::endl;
    std::cout << "a: " << a << std::endl;

    Arr e;
    e = std::move(b);
    std::cout << "e: " << e << std::endl;
    std::cout << "b: " << b << std::endl;    



    std::vector<Arr> vec;
    vec.reserve(10);
    for(int i = 0; i<10; i++){
        Arr f(10);
        vec.push_back(f);
        vec.push_back(std::move(f));
        vec.emplace_back(std::move(f));
    }
    return 0;
}
