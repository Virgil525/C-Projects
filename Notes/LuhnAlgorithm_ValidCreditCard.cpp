/*
    Luhn Algorithm
    1. Double every second digit from right to left, If doubled number is 2 digits, split them.
    2. Add all single digits from Step 1.
    3. Add all odd numbered digits from right to left.
    4. Sum results from steps 2 & 3.
    5. If step 4 is divisble by 10, # is valid.
*/

#include <iostream>

int* getEvenDigits(const int array[], const int size);
int* getOddDigits(const int array[], const int size);

int main(){
    int cardNumber[16] = {6,0,1,1,0,0,0,9,9,0,1,3,9,4,2,4};
    int size = sizeof(cardNumber)/sizeof(cardNumber[0]);
    int* Even = getEvenDigits(cardNumber, size);
    int* Odd = getOddDigits(cardNumber, size);
    int sumEven = 0;
    int sumOdd = 0;

    for(int i=0; i < size/2 ; i++){
        Even[i] *= 2;
        if ((Even[i] - 10) >= 0){
            sumEven += (Even[i] - 10);
            sumEven += (Even[i] / 10);
            continue;
        }
        sumEven += Even[i];
    }

    for(int i=0; i < size/2 ; i++){
        sumOdd += Odd[i];
    }
    
    std::cout << "Even sum: "<< sumEven<< "\n Odd sum: " << sumOdd << "\n";
    std::string message = (sumEven + sumOdd) % 10 ? "Invalid card number" : "Valid card number";
    std::cout << message;
    delete[] Even;
    delete[] Odd;

    return 0;
}

int* getEvenDigits(const int array[], const int size){
    int resultSize = size /2;
    int* result = new int[resultSize];
    int j = 0;
    for(int i = size - 2; i >= 0; i-=2){
        result[j] = array[i];
        j++;
    }
    return result;
}

int* getOddDigits(const int array[], const int size){
    int resultSize = size /2;
    int* result = new int[resultSize];
    int j = 0;int resultSize = size /2;
    int* result = new int[resultSize];
    for(int i = size - 1; i >= 0; i-=2){
        result[j] = array[i];
        j++;
    }
    return result;
}