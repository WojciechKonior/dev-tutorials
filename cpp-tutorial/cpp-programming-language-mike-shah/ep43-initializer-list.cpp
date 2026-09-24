#include <iostream>
#include <string>

class Vector3{
public:
    Vector3(): x(1.0f), y(0.0f), z(0.0f) { 
        std::cout << "default constructor\n"; 
        std::cout << x << " " << y << " " << z << std::endl;
    }
    float x, y, z;
};

std::ostream& operator<<(std::ostream& os, const Vector3& vec){
    os << vec.x << " " << vec.y << " " << vec.z;
    return os;
}

int main() {
    Vector3 myVector;
    myVector.x = 1.0f;
    myVector.y = 2.0f;
    myVector.z = 3.0f;

    std::cout << myVector << std::endl;
    return 0;
}
