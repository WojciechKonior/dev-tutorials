#include <iostream>
#include <iterator>
#include <array>

using namespace std;

int main(){ // main function is a main entrypoint
    int arr[100];
    
    std::fill(std::begin(arr), std::end(arr), 1);
    
    for (int i = 0; i<100; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    std::array<int, 20> arr2;
    std::fill(std::begin(arr2), std::end(arr2), 4);
    for (auto& a : arr2){ // for range based loop
        cout << a << " ";
    }
    cout << endl;
    
    int i = 0;
    do{
        cout << arr[i] << " ";
        i++;
    } while (i<20);
    cout << endl;
    
    i = 0;
    while(i<20){
        cout << arr[i] << " ";
        i++;
    }
    
    return 0;
}
