#include <iostream>

using namespace std;

int main(){ // main function is a main entrypoint
    
    for(int i = 0; i<10; i++){
        cout << "j: ";
        for(int j = 0; j<10; j++){
            if (j>5) continue;
            cout << j << " ";
        }
        if(i>5) break;
        cout << endl;
        cout << "i: " << i << endl;
    }
    
    return 0;
}
