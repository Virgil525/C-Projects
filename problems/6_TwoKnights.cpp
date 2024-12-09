#include <iostream>

/*
Your task is to count for k = 1,2,...,n the number of ways two knights
can be placed on a k x k chessboard so that they do not attack each other.

Input: integer n
Output: print n integers: the results.

exaple ---
intput: 8
output: 
0
6
28
96
252
550
1056
1848
*/
using namespace std;
typedef long long ll;

// total number of placing two knights on a chess board of k*k is C(k*k,2)
// C(k*k,2) = k^2 * (k^2 - 1) / 2
// Knights move in a 2x3 rectangle, There are (k-1) * (k-2) such rectangles on
// one orientation of a k*k board, so there are in total 2 * (k-1) * (k-2) such rectangles.
// For each rectangle, knights can alternate between the two positions so
// there are in total 2 * 2 * (k-1) * (k-2) ways for the knights to be able to attack
// Thus total ways of knights not being able to attack is C(k*k,2) - 2 * 2 * (k-1) * (k-2)
// Which is (k^2 * (k^2 - 1) / 2) - 2 * 2 * (k-1) * (k-2)

ll countWays(int k){
    ll totalSquares = k * k;
    ll arrangements = (totalSquares * (totalSquares - 1) / 2) - (2 * 2 * (k-1) * (k-2));
    return arrangements;
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        std::cout << countWays(i) << std::endl;
    }
    return 0;
}