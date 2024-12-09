#include <iostream>


/*
You are given a DNA sequence: a string consisting of A,C,G and T, find the longest repetition sequence
Input: String (size = n)
Output: longest repetition
*/
typedef std::string String;

int main(){
    String s;
    std::cin >> s;
    int record = 0;
    int temp = 0;
    char prev = 'A';

    for(char a : s){
        if (a == prev){
            temp++;
        } else {
            record = std::max(temp,record);
            temp = 1;
            prev = a;
        }
    }
    std::cout << record;

    return 0;
}