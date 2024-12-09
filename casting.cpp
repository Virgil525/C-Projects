#include <iostream>

class Base{
    public:
        Base(){}
        virtual ~Base(){}
};

class Derived : public Base{
    public:
        Derived(){}
        virtual ~Derived(){}
};

class AnotherClass : public Base{
    public:
        AnotherClass(){}
        ~AnotherClass(){}
};

int main(){
    double a = 5.55;
    // C style casting
    double b = (int)a + 5.22;
    std::cout << b << std::endl;

    // c++ style casting
    double c = static_cast<int>(a) + 5.22;
    std::cout << b << std::endl;

    Derived* derived = new Derived();
    Base* base = derived;

    // dynamic cast checks if the instance is indeed the type you are casting to
    AnotherClass* ac = dynamic_cast<AnotherClass*>(derived);
    if (!ac){
        std::cout << "derived is not an instance of AnotherClass" << std::endl;
    }
    Derived* ac2 = dynamic_cast<Derived*>(base);
    if (!ac2){
        std::cout << "base is not an instance of AnotherClass" << std::endl;
    }

    // reinterpret_cast performs low level memeory casting
    // only use reinterpret_cast when certain of whay you are doing
    // 1. Pointer to Pointer Conversion
    class A {};
    class B {};

    A* aC = new A();
    B* bC = reinterpret_cast<B*>(aC);

    // 2. Pointer to Integral Type Conversion
    char* p = new char[10];
    std::uintptr_t address = reinterpret_cast<std::uintptr_t>(p);

    // 3. Integral Type to Pointer Conversion
    std::uintptr_t address = 123456; 
    char* p = reinterpret_cast<char*>(address);

    return 0;
}