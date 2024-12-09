#include <iostream>
#include <string>
#include <vector>

void HelloWorld(){
    std::cout << "Hello World" << std::endl;
}
void HelloWorld2(int a){
    std::cout << "Hello World" << a <<std::endl;
}

void PrintValue(int value){
    std::cout<<"Value: " << value << std::endl;
}

void forEach(const std::vector<int>& values, void(*func)(int)){
    for(int val : values){
        func(val);
    }
}

int main(){
    HelloWorld();

    // void(*x)();
    void(*y)() = HelloWorld;
    auto x = HelloWorld;
    // this way is better
    typedef void(*zFunction)();
    zFunction Z= HelloWorld;
    typedef void(*aFunction)(int);

    aFunction a = HelloWorld2;

    a(7);
    Z();
    x();
    y();

    std::vector<int> values = {1,2,3,4,5};
    forEach(values, PrintValue);

    return 0;
}