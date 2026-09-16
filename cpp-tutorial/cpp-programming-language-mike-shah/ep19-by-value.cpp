#include <iostream>

auto SetValue(int arg) -> void {
    std::cout << "args before change: " << arg << std::endl;
    std::cout << "args address: " << (void*)&arg << std::endl;
    arg = 999;
    std::cout << "args after change: " << arg << std::endl;
}

int main(){ // main function is a main entrypoint
    
    int x = 40;
    std::cout << "value before func: " << x << std::endl;
    SetValue(x);
    std::cout << "value after func: " << x << std::endl;
    std::cout << "value address: " << (void*)&x << std::endl;
    
    return 0;
}
