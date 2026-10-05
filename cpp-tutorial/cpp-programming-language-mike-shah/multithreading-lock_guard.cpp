#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

static int shared_value = 0;
std::mutex m;

void shared_value_increment(){
    std::lock_guard<std::mutex> lockGuard(m);
    // m.lock();
    shared_value += 1;
    // m.unlock();
}

int main(){
    std::vector<std::thread> thr;

    for(int i = 0; i<100; i++){
        thr.push_back(std::thread(shared_value_increment));
    }

    for(int i = 0; i<100; i++){
        thr[i].join();
    }

    std::cout << "Shared value: " << shared_value << std::endl;
    

    return 0;
}
