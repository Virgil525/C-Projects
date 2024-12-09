#include <iostream>

typedef long long ll;
using namespace std;
/*
Your task is to calculate the number of trailing zeros in the factorial n!.
For example, 20! = 2432902008176640000 and it has 4 trailing zeros.
*/

/*
Because trailing zeros are caused by 2 * 5, and there are likely more multiples of 2 than
multiples of 5, so the trailing zeros are determined by number of 5s in it.
Thus we just need to sum up all the division results of multiples of 5 that are contained in n
n/5 , n/25, n/125 ...
*/
int main(){
    ll n;
    cin >> n;
    ll ans= 0;
    for(ll i = 5; i <= n; i*= 5){
        ans += n/i;
    }

    cout << ans << endl;

    return 0;
}