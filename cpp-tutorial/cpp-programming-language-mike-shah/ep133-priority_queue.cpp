#include <iostream>
#include <queue>

void printQueue(std::priority_queue<int> q) {
    while (!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << std::endl;
}

int main(){
    std::priority_queue<int> q; //max heap - largest element at the top
    q.push(1);
    q.push(2);
    q.push(3);
    printQueue(q);
    std::cout << q.size() << std::endl;
    q.pop();
    std::cout << q.top() << std::endl;

    q.push(4);
    q.push(5);

    printQueue(q);
    printQueue(q);
    
    return 0;
}
