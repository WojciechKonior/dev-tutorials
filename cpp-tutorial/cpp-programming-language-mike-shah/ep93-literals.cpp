#include <iostream>
#include <utility>

int main() {

    auto a = 5;
    auto b = 10u;
    auto e = 10ul;
    auto f = 10l;
    auto g = 10ll;
    auto h = 10ull;
    auto c = 15.0f;
    auto d = 20.0;
    std::cout << "a: " << a << "is type: " << typeid(a).name() << std::endl;
    std::cout << "b: " << b << "is type: " << typeid(b).name() << std::endl;
    std::cout << "c: " << c << "is type: " << typeid(c).name() << std::endl;
    std::cout << "d: " << d << "is type: " << typeid(d).name() << std::endl;
    std::cout << "e: " << e << "is type: " << typeid(e).name() << std::endl;
    std::cout << "f: " << f << "is type: " << typeid(f).name() << std::endl;
    std::cout << "g: " << g << "is type: " << typeid(g).name() << std::endl;
    std::cout << "h: " << h << "is type: " << typeid(h).name() << std::endl;
    return 0;
}
