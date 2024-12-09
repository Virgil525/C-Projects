#include <iostream>
#include <any>

// any will not do any memory allocation with types less than 32 bytes

int main(){
    std::any data;
    data = 2;
    data = "PPP";
    data = std::string("ppp");

    std::string& s = std::any_cast<std::string&>(data);

    return 0;
}