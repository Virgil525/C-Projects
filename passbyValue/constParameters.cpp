#include <iostream>

void printInfo(const std::string &name, const int &age);

int main(){
    std::string name = "YOYOYO";
    int age = 21;
    printInfo(name,age);
    return 0;
}

void printInfo(const std::string &name, const int &age){
    std::cout << name << std::endl;
    std::cout << name << std::endl;
}