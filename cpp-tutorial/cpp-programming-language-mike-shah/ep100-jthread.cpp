#include <iostream>
#include <thread>
#include <vector>

int main() {
    std::vector<std::jthread> vec;
    for(int i = 0; i<10; i++){
        vec.push_back(std::jthread([](){
            printf("Hello from thread %i\n", std::this_thread::get_id());
        }));
    }

    auto thr = std::jthread([](){ printf("Hello from %llu\n", std::this_thread::get_id()); });

    
    return 0;
}
