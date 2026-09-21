#include <iostream>
#include <functional>

int add(int x, int y) {
    return x + y;
}

int multiply(int x, int y) {
    return x * y;
}

typedef int (*FnPtrIntOps)(int, int);

int main() {

    int (*add_ptr)(int, int);
    add_ptr = add;

    int (*multiply_ptr)(int, int);
    multiply_ptr = multiply;

    
    std::cout << "Addition of 5 and 3: " << add_ptr(5, 3) << std::endl;
    std::cout << "Multiplication of 5 and 3: " << multiply_ptr(5, 3) << std::endl;
    
    FnPtrIntOps add_fn_ptr = add;
    std::function<int(int, int)> multiply_fn_ptr = multiply;

    std::cout << "Addition of 5 and 3: " << add_fn_ptr(5, 3) << std::endl;
    std::cout << "Multiplication of 5 and 3: " << multiply_fn_ptr(5, 3) << std::endl;

    return 0;
}
