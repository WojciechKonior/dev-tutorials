#include <iostream>
#include <memory>

class UsrDefCls{
public:
    UsrDefCls() { std::cout << "UsrDefCls created" << std::endl; }
    ~UsrDefCls() { std::cout << "UsrDefCls destroyed" << std::endl; }
};

typedef int (*fcn_ptr)(int, int);

int main() {
    std::weak_ptr<UsrDefCls> ptr0;
    {    
        std::shared_ptr<UsrDefCls> ptr1 = std::make_shared<UsrDefCls>();
        ptr0 = ptr1;
        {
            std::shared_ptr<UsrDefCls> ptr2 = ptr1;
            {
                std::weak_ptr<UsrDefCls> ptr3 = ptr1;
                std::cout << "Use count = " << ptr3.use_count() << std::endl;
                std::cout << "Expired = " << ptr3.expired() << std::endl;
            }
            std::cout << "Use count = " << ptr2.use_count() << std::endl;
        }
        std::cout << "Use count = " << ptr1.use_count() << std::endl;
    }
    std::cout << "Expired = " << ptr0.expired() << std::endl;
    return 0;
}
