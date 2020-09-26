The std::weak_ptr<clazz> can point only where another pointer points and it points to nullptr when the object pointed is deleted or not pointed by any other pointers anymore.

## C++ dynamic memory management
### [std::make_shared](https://en.cppreference.com/w/cpp/memory/shared_ptr/make_shared)
The non-member function of std::shared_ptr creates a shared pointer that manages a new pointer. It is equivalent to create by new&assigement.
The following two expressions have same effect, but the second one is more clear:

`std::shared_ptr<MyClass> my_class_shared_ptr {new MyClass()};`

`std::shared_ptr<MyClass> my_class_shared_ptr = std::make_shared<MyClass>();`

### [std::enable_shared_from_this](https://en.cppreference.com/w/cpp/memory/enable_shared_from_this)
This is a class which allows an object t that is currently managed by a std::shared_ptr named pt to safely generate additional std::shared_ptr instances pt1, pt2, .... that all shared ownership of t with pt.

#### std::shared_from_this
The public member function of std::enable_shared_from this, it returns a shared_ptr which shares ownership of *this. This operation is equivalent to just assigement, but more expressional.
The following two expressions have same effect, but the second one is better:

`auto my_class_shared_ptr_new = my_class_shared_ptr->shared_from_this();`

`auto my_class_shared_ptr_new2 = my_class_shared_ptr;`