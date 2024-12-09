#include <iostream>
#include <string>
#include <limits> //for std::numeric_limits

void inputFood();

int main(){
    /*
    const int SIZE = 100;
    std::string foods[SIZE];
    // fill( start location, end locatoin, content )
    fill(foods, foods + SIZE, "pizza");
    for (std::string food : foods){
        std::cout << food;
    }
    */
   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    inputFood();

    return 0;
}

void inputFood(){
    std::string foods[5];
    int size = sizeof(foods)/sizeof(foods[0]);

    for(int i = 0; i < size; i++){
        std::cout << "Enter a food you like #" << i + 1 << ": ";
        std::getline(std::cin, foods[i]);
    }

    std::cout << "You like these foods:\n";

    for(int i = 0; !foods[i].empty(); i++){
        std::cout << foods[i] << '\n';
    }
}