#include <iostream>
#include <string>

class Person{
public:
    Person(std::string s){
        m_impl = new pImplPerson;
        m_impl->m_name = s;
        m_impl->m_strength = "n/a";
        m_impl->m_speed = "n/a";
    }
    ~Person(){
        delete m_impl;
    }
    std::string GetAttributes(){
        return m_impl->m_name + ", " + m_impl->m_strength + ", " + m_impl->m_speed;
    }
private:
    struct pImplPerson{
        std::string m_name;
        std::string m_strength;
        std::string m_speed;
    };
    pImplPerson* m_impl;
};

int main() {
    Person mike("mike");
    std::cout << mike.GetAttributes() << std::endl;
    
    return 0;
}
