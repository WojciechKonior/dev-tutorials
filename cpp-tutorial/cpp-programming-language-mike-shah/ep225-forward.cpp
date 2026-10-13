#include <iostream>
#include <print>
#include <type_traits>

struct Object{

};

void func(Object& x){
    std::print("\tfunc(Object& x)\n");
}

void func(Object&& x){
    std::print("\tfunc(Object&& x)\n");
}

template <typename T>
void FuncWrapper(T&& x){
    std::print("funcWrapper(T&& x)\n");
    func(std::forward<T>(x));
}

int main(){
    Object o;
    FuncWrapper(o);
    FuncWrapper(std::move(o));
    return 0;
}
