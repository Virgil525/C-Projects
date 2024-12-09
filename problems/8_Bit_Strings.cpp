#include <iostream>
#include <math.h>

using namespace std;

#define ll long long


/*
Your task is to calculate the number of bit strings of length n.

For example, if n=3, the correct answer is 8, because the possible bit strings are 000
, 001, 010, 011, 100, 101, 110 and 111.
Input: only a input line of integer n.
Output: Print the result modulo 10^9 + 7

example: input: 3    output: 8
*/

int main(){
    const int MOD = 1e9+7;
    ll n, s = 1;
    cin >> n;
    for(int i = 0; i < n; i++){
        s = (s*2) % MOD;
    }

    cout << s << endl;

    return 0;
}