#include <iostream>

// Whenever you are writting a class that is able to have sub classes, you need
// to declare the destructor as virtual

class Base{
    public:
        Base() { std::cout << "Base constructed." << std::endl; }
        virtual ~Base() { std::cout<< "Base Destoryed." << std::endl; }
};

class Derived : public Base{
    public:
        Derived() { std::cout << "Derived constructed." << std::endl; }
        ~Derived() { std::cout<< "Derived Destoryed." << std::endl; } 
    private:
        int* m_array;
};

int main(){
    Base* base = new Base();
    delete base;
    std::cout << "_______________\n";
    Derived* derived = new Derived();
    delete derived;

    Base* poly = new Derived();
    delete poly;

    return 0;
}