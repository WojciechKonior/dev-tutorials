#include <iostream>
#include <cassert>

int main() {

    constexpr int age = -7;
    assert(age > 0 && "Age cannot be negative");
    static_assert(age>0, "Age cannot be negative");
    std::cout << "Done" << std::endl;
    return 0;
}
