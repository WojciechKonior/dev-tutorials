#include <iostream>

// Klasa bazowa (Musi mieć "virtual", aby działał dynamic_cast)
class Base {
public:
    virtual ~Base() = default; 
};

// Klasa pochodna
class Derived : public Base {
public:
    void bark() { 
        std::cout << "  -> Woof! Udalo sie wywolac metode klasy Derived.\n"; 
    }
};

class Another {

};

int main() {
    std::cout << "--- START PROGRAMU ---\n\n";

    // Tworzymy dwa rozne obiekty ukryte pod wskaznikami Base*
    Base* b1 = new Derived(); // Realnie pod spodem jest Derived
    Base* b2 = new Base();    // Realnie pod spodem jest tylko czyste Base
    Another* a1 = new Another();

    // ==========================================
    // 1. TEST STATIC_CAST (Szybki, ale bez zabezpieczen)
    // ==========================================
    std::cout << "[static_cast]\n";

    // Przypadek poprawny: wiemy, ze b1 to Derived
    Derived* s1 = static_cast<Derived*>(b1);
    s1->bark();

    // Przypadek NIEPOPRAWNY: b2 to NIE JEST Derived, ale static_cast to zignoruje!
    std::cout << "  -> Rzutujemy czyste Base na Derived za pomoca static_cast...\n";
    Derived* s2 = static_cast<Derived*>(b2); 
    
    // ODKOMENTOWANIE ponizszej linii moze wywolac crash programu (Undefined Behavior)
    // s2->bark(); 
    std::cout << "  -> Kompilator ufa programiscie. Brak bledu, ale kod jest NIEBEZPIECZNY.\n\n";

    // Another* s3 = static_cast<Another*>(b2); // nie zadziała bo całkiem różne typy
    Another* s3 = reinterpret_cast<Another*>(b2); // zadziała ale niebezpieczny
    const char* MojTekst = "Witaj swiecie";
    char* modyfikowalnyTekst = const_cast<char*>(MojTekst);

    // ==========================================
    // 2. TEST DYNAMIC_CAST (Bezpieczny, sprawdza typ w runtime)
    // ==========================================
    std::cout << "[dynamic_cast]\n";

    // Przypadek poprawny: b1 to Derived, wiec dostaniemy poprawny wskaznik
    Derived* d1 = dynamic_cast<Derived*>(b1);
    if (d1) {
        d1->bark();
        std::cout << typeid(*d1).name() << std::endl;
    }

    // Przypadek niepoprawny: b2 to tylko Base. dynamic_cast to wykryje w runtime!
    std::cout << "  -> Rzutujemy czyste Base na Derived za pomoca dynamic_cast...\n";
    Derived* d2 = dynamic_cast<Derived*>(b2);
    
    if (d2 == nullptr) {
        std::cout << "  -> SUKCES: dynamic_cast wykryl, ze b2 to nie Derived i zwrocil nullptr!\n";
        std::cout << "  -> Dzieki temu unikanelismy bledu w trakcie dzialania programu.\n";
    }

    // Czyszczenie pamieci
    delete b1;
    delete b2;

    std::cout << "\n--- KONIEC PROGRAMU ---\n";
    return 0;
}
