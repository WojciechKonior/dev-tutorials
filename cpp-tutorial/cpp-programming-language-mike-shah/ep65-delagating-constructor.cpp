#include <iostream>
#include <string>

struct Entity{
    Entity(): name{}, x{0}, y{0}, collection{nullptr} {
        name = std::to_string(x) + std::to_string(y);
        // some other instructions
    }

    Entity(std::string n): Entity() {
        name = n;
    }

    Entity(int _x, int _y): Entity() {
        x = _x;
        y = _y;
        name = std::to_string(x) + std::to_string(y);
    }

    void print(){
        std::cout << "{" << name << ", " << x << ", " << y << ", " << collection << "}\n";
    }

    std::string name;
    int x{0};
    int y{0};
    int* collection{nullptr};
};

int main() {
    Entity e{1,2};
    e.print();
    
    return 0;
}
