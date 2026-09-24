#include <iostream>
#include <string>

class Vector3{
public:
    Vector3(): x(0.0f), y(0.0f), z(0.0f) { std::cout << "default constructor\n"; }
    Vector3(const Vector3& vec): x(vec.x), y(vec.y), z(vec.z) { std::cout << "copy constructor\n"; }
    Vector3& operator=(const Vector3& vec) { 
        this->x = vec.x; this->y = vec.y; this->z = vec.z;
        std::cout << "copy-assignment operator\n"; 
        return *this; 
    }

    Vector3 operator+(const Vector3& vec) const { Vector3 res; res.x = x + vec.x; res.y = y + vec.y; res.z = z + vec.z; return res; }
    Vector3 operator++() { x++;y++;z++; return *this; }
    Vector3& operator++(const Vector3& vec) { x=vec.x+1; y=vec.y+1; z=vec.z+1; return *this; }
    ~Vector3() { std::cout << "destructor\n"; }
    float x, y, z;

    void print(){
        std::cout << "[" << this->x << "," << this->y << "," << this->z << "]\n";   
    }
};

int main() {
    Vector3 myVector;
    myVector.x = 1.0f;
    myVector.y = 2.0f;
    myVector.z = 3.0f;

    Vector3 myVector2 = myVector;
    myVector2.print();
    Vector3 myVector3(myVector);
    myVector3.print();

    Vector3 vec2 = myVector + myVector;
    vec2.print();
    return 0;
}
