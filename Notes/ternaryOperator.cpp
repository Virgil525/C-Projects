#include <iostream>
#include <string>

char isEven(int num){
    return num % 2 == 0 ? 'y' : 'n';
}

int main(){
    double grade;
    std::cout << "Whats your grade?";
    std::cin >> grade;
    grade >= 60 ? std::cout << "Good job!" : std::cout << "You did not pass, try again";
    

    int num;
    std::cout << "Enter a number to see even or odd:";
    std::cin >> num;
    std::cout << isEven(num);
    return 0;
}