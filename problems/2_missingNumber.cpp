#include <iostream>
/*
Find missing number, given input n and n-1 numbers that are distinct and between 1 and n (inclusive)
Input:
5
2 3 1 5

Output:
4

*/
typedef long long ll;

int main(){
    ll n, s = 0;
    std::cin >> n;
    for (int i = 1; i < n; i++){
        int a;
        std::cin >> a;
        s += a;
    }
    std::cout << n*(n+1)/2 - s;
    return 0;
}