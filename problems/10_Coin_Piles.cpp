#include <iostream>

typedef long long ll;
/*
You have two coin piles containing a and b coins. On each move, you can either
remove one coin from the left pile and two coins from the right pile, or two
coins from the left pile and one coin from the right pile.

Your task is to efficiently find out if you can empty both the piles.

Input
The first input line has an integer t: the number of tests.
After this, there are t lines, each of which has two integers a and b
the numbers of coins in the piles.

Output
For each test, print "Yes" if you can empty the piles and "No" otherwise

Example:
Input:
3
2 1
2 2
3 3
Output:
YES
NO
YES
*/

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll a,b;
        cin >> a >> b;
        cout << (((a+b)%3 == 0 && 2*a >= b && 2*b >= a) ? "Yes":"No") << "\n";
    }

    return 0;
}