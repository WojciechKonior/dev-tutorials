#include <iostream>
#include <cstdint>

using namespace std;

int main(){ // main function is a main entrypoint
    int64_t x = 42;
    cout << x << endl;
    cout << sizeof(x) << " bytes" << endl;
    
    bool y = true;
    float z = 3.14f;
    double d = 3.24;
    char b = 'a';
    const char* c = "abc";
    return 0;
}
