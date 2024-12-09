#include <iostream>

/*
A number spiral is an infinite grid whose upper-left square has number 1.
example:
1 2 9 10 25
4 3 8 11 24
5 6 7 12 23
16 15 14 13 22
17 18 19 20 21    

The first input line contains a integer t: the number of tests.
after this, there are t lines, each containing intergers y and x

row: y
col: x
*/
typedef long long ll;
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll y, x;
        cin >> y >> x;
        ll z = std::max(y,x);
        ll zSq = z*z;
        ll ans;
        // if at an Odd layer, zSq is at the top right corner

        if(z % 2){
            // if x is z, then we are at the right most col
            if (x == z){
                ans = zSq - y + 1;
            } else {
                ans = zSq - 2*y + 1 + x;
            }
        }  
        // if at an even layer, zSq is at the bottm left corner
        else{
            // if x is z, then we are at the right most col
            if (x == z){
                ans = zSq - 2*x + 1 + y;
            } else{
                ans = zSq - x + 1;
            }
        }
        cout << ans << '\n';
    }




    return 0;
}