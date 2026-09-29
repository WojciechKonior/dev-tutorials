#include <iostream>
#include <mutex>

class ThreadSafeCounter{
    int data = 0;
    mutable std::mutex m;

    int get() const {
        std::lock_guard<std::mutex> lk(m);
        return data;
    }

    void inc(){
        std::lock_guard<std::mutex> lk(m);
        ++data;
    }
};

int main() {

    
    return 0;
}
