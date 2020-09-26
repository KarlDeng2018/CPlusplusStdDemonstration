#include <iostream>

#include <memory>
//using namespace std;
class MyClass:
        public std::enable_shared_from_this<MyClass>

        {
public:
    MyClass():
    i(0){
        std::cout << "https://en.cppreference.com/w/cpp/memory/enable_shared_from_this" << std::endl;
    }
    ~MyClass(){
        std::cout << this << std::endl;
    }

    int get_i() {
        return i;
    }
    void set_i(int _i) {
        i = _i;
    }
private:
    int i;
    void test_func() {
        std::shared_ptr<MyClass> ptr2 = shared_from_this();
        auto ptr = std::weak_ptr<MyClass>(shared_from_this());
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
//    MyClass my_class;
//
//    auto ptr = my_class.shared_from_this();

//    std::shared_ptr<MyClass> my_class_shared_ptr {new MyClass()};
    std::shared_ptr<MyClass> my_class_shared_ptr = std::make_shared<MyClass>();
    std::cout << "my_class_shared_ptr[" << &my_class_shared_ptr << "][" << my_class_shared_ptr->get_i() << "]" << my_class_shared_ptr.get() << "use_count:" << my_class_shared_ptr.use_count() << std::endl;
    auto my_class_shared_ptr_new = my_class_shared_ptr->shared_from_this();
    std::cout << "my_class_shared_ptr[" << &my_class_shared_ptr << "][" << my_class_shared_ptr->get_i() << "]" << my_class_shared_ptr.get() << "use_count:" << my_class_shared_ptr.use_count() << std::endl;
    std::cout << "my_class_shared_ptr_new[" << &my_class_shared_ptr_new << "][" << my_class_shared_ptr_new->get_i() << "]" << my_class_shared_ptr_new.get() << "use_count:" << my_class_shared_ptr_new.use_count() << std::endl;
    auto my_class_shared_ptr_new2 = my_class_shared_ptr;

//    auto my_class_shared_ptr_new = my_class_shared_ptr;
//    auto my_class_shared_ptr_new2 = my_class_shared_ptr;

    my_class_shared_ptr->set_i(1);
    my_class_shared_ptr_new->set_i(2);
    my_class_shared_ptr_new2->set_i(3);


    std::cout << "my_class_shared_ptr[" << &my_class_shared_ptr << "][" << my_class_shared_ptr->get_i() << "]" << my_class_shared_ptr.get() << "use_count:" << my_class_shared_ptr.use_count() << std::endl;
    std::cout << "my_class_shared_ptr_new[" << &my_class_shared_ptr_new << "][" << my_class_shared_ptr_new->get_i() << "]" << my_class_shared_ptr_new.get() << "use_count:" << my_class_shared_ptr_new.use_count() << std::endl;
    std::cout << "my_class_shared_ptr_new2[" << &my_class_shared_ptr_new2 << "][" << my_class_shared_ptr_new2->get_i() << "]" << my_class_shared_ptr_new2.get() << "use_count:" << my_class_shared_ptr_new2.use_count() << std::endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
