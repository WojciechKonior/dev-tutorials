#include <iostream>
#include <list>
#include <span>

void printList(const std::list<int>& list){
    for(auto& el: list){
        std::cout << el << " ";
    }
    std::cout << std::endl;
}

int main(){
    std::list<int> myList;
    myList.push_back(1);
    myList.push_back(2);
    myList.push_front(0);
    myList.push_front(-1);
    myList.insert(myList.begin(), 100);
    myList.insert(myList.end(), 200);
    myList.erase(myList.begin());

    myList.sort();
    myList.reverse();
    myList.remove_if([](int x){ return x<0; });
    printList(myList);

    std::list<int> anotherList = {10, 20, 30};
    myList.merge(anotherList);

    printList(myList);

    return 0;
}
