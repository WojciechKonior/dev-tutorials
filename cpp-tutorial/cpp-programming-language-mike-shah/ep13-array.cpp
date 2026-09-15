#include <iostream>
#include <array>
#include <numeric>
#include <iterator>

using namespace std;

int main(){ // main function is a main entrypoint
    std::array<int, 5> a;
    a[0] = 1;
    
    int ids[100]; // raw array is simple but unsafe
    std::iota(begin(ids), end(ids), 30);
    
    for(int i = 0; i<100; i++) cout << ids[i] << " ";
    ids[101] = 10; // bad but no compile&runtime error
    a.at(5) = 9; // bad and runtime error
    a[6] = 10; //bad and runtime error
    
    return 0;
}
