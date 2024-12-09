#include <iostream>

enum Day {Sunday = 0, Monday = 1, Tuesday = 2, Wednesday = 3, Thursday = 4, Friday = 5, Saturday = 6};

int main(){
    Day today = Sunday;

    switch(today){
        case Sunday: std::cout << "It is Sunday!\n";
                    break;
        case Monday: std::cout << "It is Monday!\n";
                    break;
        case Tuesday: std::cout << "It is Tuesday!\n";
                    break;
        case Wednesday: std::cout << "It is Wednesday!\n";
                    break;
        case Thursday: std::cout << "It is Thursday!\n";
                    break;
        case Friday: std::cout << "It is Friday!\n";
                    break;
        case Saturday: std::cout << "It is Saturday!\n";
                    break;
    }
}