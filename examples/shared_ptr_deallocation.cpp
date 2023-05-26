#include <iostream>
#include <memory>
#include <array>

/**
 * Question: 
 * What is memory freed only after weak_ptr going out of scope? 
*/

void* operator new(std::size_t n) {
    std::cout << "--- Allocating " << n << " bytes ---" << std::endl;
    return std::malloc(n);
}

void operator delete(void* p) noexcept {
    std::cout << "--- Deallocating memory address: "<< p << " ---" << std::endl;
    std::free(p);
}

class MyClass {
public:
    std::array<int, 200> arr{1};

    MyClass()  { std::cout << "MyClass constructed\n"; }
    ~MyClass() { std::cout << "MyClass destroyed\n";   }
};

int main()
{   /* ==== Create shared pointer ==== */
    auto sp = std::make_shared<MyClass>(); // 1
    //auto sp = std::shared_ptr<MyClass>(new MyClass()); // 2

    /* ==== Create 0..n copies of the pointer ==== */
    std::cout<<"Making copy of sp" << std::endl;
    auto sp2 = sp;

    /* ==== Create weak pointer ==== */
    std::cout<<"Creating weak ptr from sp" << std::endl;
    std::weak_ptr<MyClass> wp = sp;

    /* ==== Null all shared pointers ==== */
    std::cout<<"Both shared ptrs going out of scope" << std::endl;
    sp = nullptr;
    sp2 = nullptr;

    /* ==== Weak pointer going out of scope ==== */
    std::cout<<"Only weak ptr remains, going out of scope now" << std::endl;

    return 0;
}

/**
 * Output: [1]
 * --- Allocating 816 bytes ---
 * MyClass constructed
 * Making copy of sp
 * Creating weak ptr from sp
 * Both shared ptrs going out of scope
 * MyClass destroyed
 * Only weak ptr remains, going out of scope now
 * --- Deallocating memory address: 0x555bbc0e52c0 ---
 * 
 * Output: [2]
 * --- Allocating 800 bytes ---
 * MyClass constructed
 * --- Allocating 24 bytes ---
 * Making copy of sp
 * Creating weak ptr from sp
 * Both shared ptrs going out of scope
 * MyClass destroyed
 * --- Deallocating memory address: 0x5576fb5172c0 ---
 * Only weak ptr remains, going out of scope now
 * --- Deallocating memory address: 0x5576fb5175f0 ---
 * 
*/