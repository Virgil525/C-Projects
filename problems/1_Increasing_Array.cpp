#include <iostream>

/*
You are given an array of n integers. You want to modify the array so it is increasing
On each turn, you may increase the value of any element by one. what is the minimum number
of turns required?

Input: 
n (size)
x1,x2,x3...,xn (ints)
*/

typedef long long ll;

int main(){
    int n;
    std::cin >> n;
    int maxi = 0;
    ll ans =0;
    for (int i = 0; i < n; i++){
        int x;
        std::cin >>x;
        // keep track of the max from left to right one by one
        maxi = std::max(x, maxi);
        // calculate the steps needed on this turn and add to total steps
        ans += maxi-x;
    }
    std::cout << ans;
}