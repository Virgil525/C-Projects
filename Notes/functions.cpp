#include <iostream>

int num = 1;
void function1(std::string name);
void bakePizza();
void bakePizza(std::string topping1);
void bakePizza(std::string topping1, std::string topping2);

int main(){
    std::string name = "YOYO";
    int num = 2;

    // ::num will use the global variable
    std::cout << num << ::num;
    
    function1(name);
}

void function1(std::string name){
    std::cout<< name <<"did something";
}

// overloaded functions
void bakePizza(){
    std::cout << "Here is your pizza!\n";
}
void bakePizza(std::string topping1){
    std:: cout << "Here is your "<< topping1 <<" pizza!\n";
}
void bakePizza(std::string topping1, std::string topping2){
    std:: cout << "Here is your "<< topping1 << "and" << topping2 <<" pizza!\n";
}