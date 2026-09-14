#include <iostream>
#include <cstdint>

using namespace std;

int main(){ // main function is a main entrypoint
    int64_t a = 10; //mutualable variable
    a = 20;
    cout << a << endl;
    
    const int64_t b = 20;
    // b = 40; // bad 
    cout << a << endl;
    return 0;
}
