#include <iostream>
#include <cstdint>


int main(){
    int8_t a = 10;
    int16_t b = 10;
    int32_t c = 20;
    int64_t d = 20;
    std::cout << sizeof(a)*8 << " ";
    std::cout << sizeof(b)*8 << " ";
    std::cout << sizeof(c)*8 << " ";
    std::cout << sizeof(d)*8 << " ";


    return 0;
}
