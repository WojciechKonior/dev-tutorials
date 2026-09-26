#include <iostream>
#include <string>

void foo(){
    static int a_static = 0;
    a_static++;
    std::cout << a_static << " ";
}

int main() {
    for(int i = 0; i<10; i++)
        foo();
    std::cout << std::endl;
    // to check where is stored use command: objdump -t ./main
    
    return 0;
}
