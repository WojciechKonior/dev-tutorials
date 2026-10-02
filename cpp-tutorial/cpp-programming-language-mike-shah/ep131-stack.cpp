#include <iostream>
#include <stack>

void printStack(std::stack<int> s) {
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
}

int main(){
    std::stack<int> s; //lifo - last in first out
    s.push(1);
    s.push(2);
    s.push(3);
    std::cout << s.top() << std::endl;
    std::cout << s.size() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;

    s.push(4);
    s.push(5);

    printStack(s);
    printStack(s);
    
    return 0;
}
