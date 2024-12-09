#include <iostream>
#include <ctime>

int main(){

    srand(time(0));
    int randNum = rand() % 5 + 1;

    switch(randNum){
        case 1: 
            std::cout << "You win 1 pp\n";
            break;
        case 2: 
            std::cout << "You win 2 pp\n";
            break;
        case 3: 
            std::cout << "You win 3 pp\n";
            break;
        case 4: 
            std::cout << "You win 4 pp\n";
            break;
        case 5: 
            std::cout << "You win 5 pp\n";
            break;

    }
}