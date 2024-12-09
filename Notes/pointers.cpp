#include <iostream>

int main(){

    std::string name = "moloch";
    std::string *pName = &name;
    std::cout << *pName <<std::endl;

    int age = 21;
    int *pAge = &age;
    std::cout << *pAge;

    // good practice to assign null pointer value to a new pointer if not address is given currently
    int *pointer = nullptr;
    int x = 123;
    pointer = &x;

    if(pointer == nullptr){
        std::cout << "failed to assign address";
    } else{
        std::cout << "address" << pointer << " is assigned";
        std::cout << "value: " << *pointer ;
    }
    return 0;
}