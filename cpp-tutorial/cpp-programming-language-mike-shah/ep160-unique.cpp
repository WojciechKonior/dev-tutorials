#include <iostream>
#include <algorithm>
#include <deque>


void printContainer(auto sp){
    for(const auto& s : sp){
        std::cout << s << " ";
    }
    std::cout << std::endl;
}

int main(){
    std::deque<int> dq{1, 2, 3, 4, 5, 6, 7, 7, 8, 8, 9};
    printContainer(dq);
    dq.erase(std::unique(dq.begin(), dq.end()), dq.end());
    printContainer(dq);
    dq.erase(std::remove(dq.begin(), dq.end(), 6), std::end(dq));
    printContainer(dq);

    std::deque<int> dq2;
    std::unique_copy(dq.begin(), dq.end(), std::back_inserter(dq2));
    printContainer(dq2);
    return 0;
}
