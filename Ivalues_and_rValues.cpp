#include <iostream>

// L values are varaibles or values that has a memory location
// r values are values that are created temperarily 

// This function takes in an l value reference which means passing r values into the function would not work
// you can work around this by making it a const l value reference, which when you passing in r values,
// const reference is conpatible with both l and r values
void PrintName(std::string& name){
    std::cout << name << std::endl;
}

// to just accept a R value or a temp value, you can ask for a r value reference
void PrintNameRValue(std::string&& name){
    std::cout << name << std::endl;
}

int main(){

    std::string name = "pp";
    PrintName(name);
    PrintNameRValue("pp");

    return 0;
}