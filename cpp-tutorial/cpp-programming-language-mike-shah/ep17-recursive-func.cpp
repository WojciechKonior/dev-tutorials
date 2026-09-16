#include <iostream>

auto countdown(int n) -> int{
    if (n==0) {
        std::cout <<"0...blast off! " << std::endl;
        return 0;
    }
    
    std::cout << n << " ";
    return countdown(n-1);
}

int main(){ // main function is a main entrypoint
    
    countdown(10);
    // countdown(500000); // stack overfloww
    return 0;
}
