#include <iostream>

int main(){

    srand(time(NULL));
    // dice with 6 sides
    int num = (rand() % 6) + 1;
    std::cout << num;

    return 0;
}