#include <iostream>

int main() {
    int num;
    int guess;
    int tries;

    srand(time(NULL));
    num = rand() % 100 + 1;

    std::cout << "Number guessing game \n";

    do{
        std::cout << "Enter a guess between 1-100";
        std::cin >> guess;
        tries++;

        if(guess>num){
            std::cout << "Too High";
        } else if (guess<num){
            std::cout << "Too low";
        } else if (guess == num){
            std::cout << "Correct! You took " << tries << "tires!";
        } else {
            std::cout << "invalid input!";
        }
    }while(guess != num);
}