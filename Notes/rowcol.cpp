#include <iostream>

int main(){
    int row, col;
    std::cout << "How many rows? ";
    std::cin >> row;
    std::cout << "How many columns? ";
    std::cin >> col;
    for(int i = 0; i < row; i++){
        for(int j = 0; j<col;j++){
            std::cout << "*";
        }
        std::cout<< "\n";
    }
}