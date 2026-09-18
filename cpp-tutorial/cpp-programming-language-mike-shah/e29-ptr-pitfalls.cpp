#include <iostream>

int* returnPointer() {
    int result = 42;
    return &result;
}

int main() {

    // nullptr dereference
    int* a = nullptr;
    *a = 10; // This will cause a segmentation fault because 'a' is a null pointer

    // memory leak
    int* b = new int; // This, without delete, will cause a memory leak
    *b = 20; 
 
    // dangling pointer
    int* px = returnPointer(); // This will cause undefined behavior because 'result' is a dangling pointer

    // double free
    int* x = new int[10];
    delete x;
    delete x; // This will cause a double free error because 'x' has already been deleted
    
    return 0;
}
