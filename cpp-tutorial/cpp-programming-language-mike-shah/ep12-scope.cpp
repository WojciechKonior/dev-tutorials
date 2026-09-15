#include <iostream>

using namespace std;

int main(){ // main function is a main entrypoint
    int a = 10;
    a = 20;
    {
        int b = 20;
        b = 40;
    }
    // b = 4; // bad
    
    int b = 4;
    b = 40;
    return 0;
}
