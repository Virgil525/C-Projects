#include <iostream>
#include <string>

int main(){
    std::string name;

    std::cout << "Enter your name: ";

    do{
        std::getline(std::cin >> std::ws, name);
    }while(name.empty());
    if(name.empty()){
        std::cout << "Empty input";
    }
    if(name.length() > 12){
        std::cout << "Your name can't be over 12 characters";
    } else {
        std::cout << "Welcome " << name;
        name.append("@gmail.com");
        std::cout << "Your email will be " << name;
        std::cout << "Your name start with " << name.at(0);
        name.insert(0,"userName:");
        
        std::cout << name;
    // remove first 9 characters ("userName:") begin index0, endnig index9
        name.erase(0,9);
        if (name.find(' ') <= 20){
            std::cout << "\nYour have a space char in your name at position: "<< name.find(' ');
        }
        name.clear();

        std::cout << "name cleared" << name;
    }
    return 0;
}