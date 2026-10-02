#include <iostream>
#include <algorithm>

template<typename T>
class FixedSizeArray {
public:
    struct iterator{
        using Category = std::forward_iterator_tag;
        using Distance = std::ptrdiff_t;
        using value_type = T;
        using Pointer = T*;
        using Reference = T&;

        iterator(Pointer ptr) : mPtr(ptr) {}

        Reference operator*() const {
            return *mPtr;
        }

        Pointer operator->() const {
            return mPtr;
        }

        iterator& operator++(){
            ++mPtr;
            return *this;
        }

        iterator operator++(T){
            iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        friend bool operator==(const iterator& lhs, const iterator& rhs){
            return lhs.mPtr == rhs.mPtr;
        }

        friend bool operator!=(const iterator& lhs, const iterator& rhs){
            return lhs.mPtr != rhs.mPtr;
        }

    private:
        Pointer mPtr;
    };
public:
    T* mData;
    size_t mCapacity;

    FixedSizeArray(size_t capacity) : mCapacity(capacity) {
        mData = new T[mCapacity];
    }
    ~FixedSizeArray() {
        if(nullptr != mData){
            delete[] mData;
            mData = nullptr;
        }
    }
    T& operator[](size_t index){
        return mData[index];
    }
    size_t capacity() const {
        return mCapacity;
    }
    iterator begin(){
        return iterator(&mData[0]);
    }
    iterator end(){
        return iterator(&mData[mCapacity]);
    }
};

int main(){
    using T = FixedSizeArray<int>;
    T c(5);

    std::cout << "C-Style Loop" << std::endl;
    for(size_t i = 0; i<c.capacity(); ++i){
        std::cout << c[i] << std::endl;
    }

    std::cout << "C++98 Style iterator loop" << std::endl;
    for(T::iterator it = c.begin(); it != c.end(); ++it){
        std::cout << *it << std::endl;
    }

    std::cout << "std:algorithm loop" << std::endl;
    std::for_each(c.begin(), c.end(), [](int& i){ std::cout << i << std::endl; });

    std::cout << "ranged-for loop" << std::endl;
    for(int& i : c){
        std::cout << i << std::endl;
    }

    return 0;
}
