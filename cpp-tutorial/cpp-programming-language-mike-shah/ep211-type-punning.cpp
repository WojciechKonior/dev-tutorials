#include <iostream>
#include <cstddef>
#include <print>

int main(){
    unsigned int data = 0xff'00'ff'00;
    std::print("{:0>32b}\n", data);
    unsigned char* byte = reinterpret_cast<unsigned char*>(&data);

    for(int i = 0; i<4; i++)
        std::print("{:0>8b}\n", byte[i]);

    std::byte* byte2 = reinterpret_cast<std::byte*>(&data);
    for(int i = 0; i<4; i++)
        std::print("{:0>8b}\n", (unsigned char)byte2[i]);

    return 0;
}
