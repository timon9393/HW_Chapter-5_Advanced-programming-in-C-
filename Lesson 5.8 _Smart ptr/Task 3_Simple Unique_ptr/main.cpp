#include <iostream>

template <typename T>
class UniquePtr {
private:
    T* ptr;

public:
    UniquePtr(T* ptr) : ptr(ptr) {}

    T& operator*() {
        return *ptr;
    }

    T* release() {
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }

    ~UniquePtr() {
        delete ptr;
    }

    UniquePtr(const UniquePtr<T>& other) = delete;
    UniquePtr<T>& operator=(const UniquePtr<T>& other) = delete;
};

int main() {
    UniquePtr<int> ptr(new int(10));
    std::cout << *ptr << std::endl;

    int* raw_ptr = ptr.release();

    delete raw_ptr;

    return 0;
}