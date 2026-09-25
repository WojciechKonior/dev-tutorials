#include <iostream>

class Base {
public:
    Base() {std::cout << "Base constructed\n"; }
    ~Base() {std::cout << "Base destructed\n"; }

public:
    int m_publ;
protected:
    int m_prot;
private:
    int m_priv;
};

class DerivPub: public Base {
public:
    DerivPub() {
        std::cout << "DerivPub constr. \n"; 
        m_publ = 1;
        m_prot = 2;
        // m_priv = 3; // error: is private within this context
    }
    ~DerivPub() {
        std::cout << "DerivPub destr. \n";
    }
};

class DerivProt: protected Base {
public:
    DerivProt() {
        std::cout << "DerivProt constr. \n";
        m_publ = 1;
        m_prot = 2;
        // m_priv = 3; // error: is private within this context
    }
    ~DerivProt() {
        std::cout << "DerivProt destr. \n";
    }
};

class DerivPriv: private Base{
public:
    DerivPriv(){
        std::cout << "DerivProt constr. \n";
        m_publ = 1;
        m_prot = 2;
        // m_priv = 3; // error: is private within this context
    }
    ~DerivPriv(){
        std::cout << "DerivPriv destr. \n";
    }
};

int main() {
    
    DerivPub a;
    a.m_publ = 2;
    // a.m_prot = 3; // error: is protected within this context
    // a.m_priv = 4; // error: is private within this context

    DerivProt b;
    // b.m_publ = 2; // error: is inaccessible within this context
    // b.m_prot = 3; // error: is protected within this context
    // b.m_priv = 4; // error: is private within this context

    DerivPriv c;
    // b.m_publ = 2; // error: is inaccessible within this context
    // b.m_prot = 3; // error: is protected within this context
    // b.m_priv = 4; // error: is private within this context
    
    return 0;
}
