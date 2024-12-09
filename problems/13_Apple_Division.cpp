#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <limits>

typedef long long ll;
using namespace std;

/*
There are n apples with known weights. Your task is to divide the apples into
two groups so that the difference between the weights of the groups is minimal

Input:
The first input line has an integer n: the number of apples
The next line has n integers p1,p2,p2,...,pn: the weight of each apple

Output:
Print one integer: the minimum difference between the weights of the groups

Constraints:
1 < n <= 20
1 <= p <= 10^9

*/

/*
There are n apples, the number of subsets of n items is n^2, this is a permutation
with repetition problem, think of it as each
apple is a distinct object, it is eigther in a set or not in a set. That is two 
possible states and according to the permutation formula, when choosing r items of
n possible states, there are n^r ways which in this case is n^2.
*/
int main(){
    int n;
    cin >> n;
    std::vector<ll> weights(n);
    ll totalWeight = 0;
    for(int i = 0; i < n; i++)
        cin >> weights[i], totalWeight+=weights[i];
    // 1<<n is left shift of 1 which evaluates to 2^n
    // numeric_limits gives the largest possible number which is quite useful
    // when initiating a comparison of some sort that updates when a smaller value
    // is detacted. 
    ll minDiff = std::numeric_limits<long long>::max();
    for(int i = 0; i < (1<<n); i++){
        ll subsetWeight = 0;
        for(int j = 0; j < n; j++){
            if(i&(1<<j)){
                subsetWeight += weights[j];
            }
        }
        ll weightDiff = std::abs(totalWeight - 2 * subsetWeight);
        minDiff = std::min(minDiff, weightDiff);
    }
    
    std::cout << minDiff << std::endl;

    return 0;
}

