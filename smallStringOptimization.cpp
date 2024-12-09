#include <iostream>
#include <string>

void* operator new(size_t size){
    std::cout<< "Allocating " << size << " bytes\n";
    return malloc(size);
}

int main (){
    std::string name = "pppppppppppppppppppppppppppp\
    pppppppppppppppppppppppppppppppppppppppppppppppppppp\
    ppppppppppppppppppppppppppppppppppppppppppppppp\
    pppppppppppppppppppppppppppppppppppppppppppppppppppppppppp\
    pppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp\
    pppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp\
    ppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp";

    std::cout<< "String size: " << name.size() << std::endl;
    std::cout << "string size: " << name.capacity() << std::endl;
    int* testAllocation = new int; // This should trigger the custom 'new' operator
    delete testAllocation;
    return 0;
}
