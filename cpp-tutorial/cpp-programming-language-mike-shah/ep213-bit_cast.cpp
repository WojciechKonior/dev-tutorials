#include <iostream>
#include <cstddef>
#include <print>

void doublePunning(auto d){
    std::byte* b = reinterpret_cast<std::byte*>(&d);
    unsigned long long* b2 = reinterpret_cast<unsigned long long*>(&d);
    unsigned long long b3 = std::bit_cast<unsigned long long>(d);
    std::print("{:0<64b}\n", b3);
    std::print("{:0<64b}\n", b2[0]);
    for(int i = sizeof(d)-1; i>-1; --i)
        std::print("{:0>8b} ", (char)b[i]);
    std::print("\n");
}

int main(){
    double d = -1.0;
    doublePunning(d);

    return 0;
}
