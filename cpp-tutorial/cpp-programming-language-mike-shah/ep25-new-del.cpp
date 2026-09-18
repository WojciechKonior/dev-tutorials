#include <iostream>

int main()
{
    int a = 1;
    char b = 2;
    float c = 3;
    int d[2] = {4, 5};
    int* p = new int(6);
    // delete p; //memory leak. To check you can run $valgrind --leak-check=full ./main
    return 0;
}
