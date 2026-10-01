#include <iostream>
#include <deque>

int main(){
    std::deque<int> d = {1, 2, 3, 4, 5};
    for(int i = 0; i < 36; i++){
        d.push_back(i);
    }

    d.push_back(42);
    d.push_front(99);
    std::cout << d.front() << std::endl;
    std::cout << d.back() << std::endl;
    std::cout << d.at(3) << std::endl;
    d.pop_back();
    d.pop_front();
    d.insert(d.begin(), 77);
    std::cout << d[3] << std::endl;
    std::cout << d.size() << std::endl;
    std::cout << sizeof(d)/4 << std::endl;
    
    return 0;
}
