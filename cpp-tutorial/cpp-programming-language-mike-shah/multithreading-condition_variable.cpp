#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

std::mutex mtx;
std::condition_variable cv;

int main(){
    int result = 0;
    bool notified = false;

    std::thread reporter([&](){
        std::unique_lock<std::mutex> lock(mtx);
        if(!notified){
            cv.wait(lock);
        }
        std::cout << "Reporter, result is: " << result << std::endl;

    });
    std::thread worker([&](){
        std::unique_lock<std::mutex> glock(mtx);
        result = 1+2+3;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "Worker: work complete" << std::endl;
        cv.notify_one();
    });

    reporter.join();
    worker.join();

    return 0;
}
