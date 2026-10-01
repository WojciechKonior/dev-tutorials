#include <iostream>
#include <forward_list>

void printList(const std::forward_list<int>& lst) {
    for (const auto& val : lst) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main(){
    std::forward_list<int> myList{1,2,3,4};

    myList.push_front(0);
    printList(myList);

    auto pos = begin(myList);
    std::advance(pos, 3);

    myList.insert_after(pos, 99);
    std::forward_list<int> anotherList{5,6,7};
    myList.merge(anotherList);
    myList.unique();
    myList.sort();
    std::forward_list<int> anotherList2{8,9,10};
    myList.splice_after(myList.before_begin(), anotherList2);

    printList(myList);

    std::cout << std::distance(begin(myList), end(myList)) << std::endl;

    std::cout << *std::next(begin(myList), 2) << std::endl;
    // std::cout << *std::prev(std::next(begin(myList), 2), 1) << std::endl;

    return 0;
}
