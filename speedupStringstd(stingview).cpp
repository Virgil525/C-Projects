#include <iostream>
#include <string>
#include <string_view>

void* operator new(size_t size){
    std::cout << "allocated once" << std::endl;
    return malloc(size);
}

// taking in a string_view = no allocation
void PrintName(const std::string_view name){
    std::cout << name << std::endl;
}

// in C++17, string size < 32bytes are allocated on the stack
int main(){
    std::string name = "Moloch pppppppp";

#if 0
    std::string firstName = name.substr(0,6);
    std::string lastName = name.substr(7,8);
#else
    ////                        c_str() gives a const char*
    /// now only 1 original allocation is done
    std::string_view firstName(name.c_str(),6);
    std::string_view lastName(name.c_str()+7, name.length());
#endif
    PrintName(firstName);
    PrintName(lastName);

    // or just use C string to eliminate allocation
    const char* dogName = "Moloch";

    return 0;
}