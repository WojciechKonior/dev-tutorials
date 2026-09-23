#include <iostream>
#include <string>

class Student {
public:
    Student();
    Student(const std::string& name);
    ~Student();

public:
    std::string pName;
};

Student::Student(){ std::cout << "Constructing empty student" << std::endl; }
Student::Student(const std::string& name){ this->pName=name; std::cout << "Constructing student " << this->pName << std::endl; }
Student::~Student() { std::cout << "Deconstructing student " << pName << std::endl; }

int main() {
    Student s("Mike");
    Student s2("Wojtek");
    return 0;
}
