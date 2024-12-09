#include <iostream>

double getTotal(double prices[], int size);
int searchArray(int numbers[], int myNum, int size);

int main(){
    std::string cars[] = {"Ferrari LaFerrari", "Maseratti GTMC", "RollsRoyce Ghost"};
    std::cout << cars[0] << '\n';
    std::cout << cars[1] << '\n';
    std::cout << cars[2] << '\n';

    std::string cars1[3];
    cars1[0] = "Mercedes S680";
    cars1[1] = "BMW M850";
    cars1[2] = "Audi S8";
    std::cout << cars1[0] << '\n';
    std::cout << cars1[1] << '\n';
    std::cout << cars1[2] << '\n';

    // 
    std::cout << "size of a string " << sizeof(std::string) << '\n';
    std::cout << "size of a char " << sizeof(char) << '\n';
    std::cout << "size of an int " << sizeof(int) << '\n';
    std::cout << "size of a double " << sizeof(double) << '\n';
    std::cout << "size of a boolean " << sizeof(bool) << '\n';
    std::cout << "size of an array of char " << sizeof(char[5]) << '\n';

    char grades[] = {'A','B','C','D'};
    std::cout << "number of elements in array " << sizeof(grades)/sizeof(char) << '\n';

    std::string students[] = {"Spongebob", "Squidward", "Patrick"};
    for (int i = 0; i < sizeof(students)/sizeof(std::string); i++){
        std::cout<< students[i]<<'\n';
    }

    // for each loop
    for(std::string student : students){
        std::cout << student << '\n';
    }

    double prices[] = {69.99, 56,49, 99.99};
    int size = sizeof(prices)/sizeof(double);
    std::cout << getTotal(prices, size);

    int numbers[] = {1,2,3,4,5,6,7,8,9,10};
    int numbersSize = sizeof(numbers)/sizeof(numbers[0]);
    int index;
    int myNum;

    std::cout << "Enter a number to search for: \n";
    std::cin >> myNum;
    std::cout << "Your number was found at index: " <<searchArray(numbers,myNum,numbersSize)<< "\n";

    return 0;
}

double getTotal(double prices[], int size){
    double temp = 0;
    for (int i = 0; i < size; i++){
        temp += prices[i];
    }
    return temp;
}

int searchArray(int numbers[], int myNum, int size){
   for (int i = 0; i < size; i++){
        if (numbers[i] == myNum){
            return i;
        }
   } 
   return -1;
}