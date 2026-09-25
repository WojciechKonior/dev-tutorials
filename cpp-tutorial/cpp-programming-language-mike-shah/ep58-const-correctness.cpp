#include <iostream>
#include <string>

void printValue(const int& value){ std::cout << value << std::endl; }

class SomeClass{
public: 
    void SetValue(const int& val){ m_value = val; }
    void PrintValue() const { std::cout << m_value << std::endl; }
private:
    int m_value;
};

int main() {
    SomeClass cls;
    cls.SetValue(10);

    const int a = 10; //first use of const: const value
    printValue(10); //second use of const: const function parameter
    cls.PrintValue(); // third use of const: const member function to protect the internal value
    return 0;
}
