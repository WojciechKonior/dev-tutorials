#include <iostream>

auto add(int a, int b) -> int;
auto add(float a, float b) ->float;
auto print(void) -> void;

int main(){ // main function is a main entrypoint
    
    std::cout << "1+2=" << add(1,2) << std::endl;
    std::cout << "2.2+3.3" << add(2.2f, 3.3f) << std::endl;
    print();
    return 0;
}

auto add(int a, int b) -> int {
    return a + b;
}

auto add(float a, float b) -> float {
    return a + b;
}

auto print(void) -> void {
    std::cout << "hello function" << std::endl;
}
