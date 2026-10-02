#include <iostream>
#include <queue>

void printQueue(std::queue<int> q) {
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;
}

int main(){
    std::queue<int> q; //fifo - first in first out
    q.push(1);
    q.push(2);
    q.push(3);
    printQueue(q);
    std::cout << q.size() << std::endl;
    q.pop();
    std::cout << q.front() << std::endl;
    std::cout << q.back() << std::endl;

    q.push(4);
    q.push(5);

    printQueue(q);
    printQueue(q);
    
    return 0;
}
