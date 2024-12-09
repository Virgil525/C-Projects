#include <iostream>

int main(){

    int *pNum = nullptr;
    pNum = new int;

    *pNum = 21;
    std::cout << pNum << "  " << *pNum;

    char *pGrades = nullptr;
    int size;
    std::cout << "How many grades to enter in?: ";
    std::cin >> size;
    pGrades = new char[size];
    for(int i = 0; i<size; i++){
        std::cout<< "Enter grade #" << i << " :";
        std::cin >> pGrades[i];
    }

    delete pNum;
    delete[] pGrades;

    return 0;
}
