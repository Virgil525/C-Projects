#include <iostream>

int main() {
    if (true && true){
        std::cout << "true";
    }
    if (true || false){
        std::cout << "true";
    }
    if (!false){
        std::cout << "true";
    }

    return 0;
}