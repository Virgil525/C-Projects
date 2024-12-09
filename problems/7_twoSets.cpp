#include <iostream>
#include <vector>

/*
Task is to divide the numbers 1,2,3,....,n into two sets
of equal sum.

input: int n
output:
print Yes if the division is possible and No other wise.
After this, if the division is possible, print the number of elements
in the first set followed by the elements themselves in a separate line
and then print the second set in a similar way.

Example:
input: 
7
Output:
YES
4
1 2 4 7
3
3 5 6
*/

using namespace std;
typedef long long ll;
int main(){
    int n;
    cin >> n;
    // Total sum of the numbers need to be even for this to work, because needs to be 
    // divisible by 2
    // Since the sum of first n numbers is n(n+1)/2, to have the sum divisible by 2
    // means n(n+1) must be divisible by 4
    // since n and n+1 are consecutive numbers, to be divisible by 4, one of them must
    // be a multiple of 4 this gives 2 cases lead to the sum divisible by 2
    // : n = 4k and (n+1) = 4k -> n = 4k + 3 -> n%4 = 3
    // case1:      case2:
    // 4k(4k +1)   (4k+3)(4k + 4) or n % 4 = 3

    // For the case n = 4k for some number k, we now verified the seperation to be feasible,
    // now we just need to get the elements in two sets, since n = 4k, we can just 
    // divide the set into quandruplets since a quadruplet is symeetrical (1+4 = 2+3)
    // in a quadruplet, the first and last number {1,2,3,4} will have a remainder of 1 and 0
    // middle two will havea remainder of 2 and 3, so we just put all elements with a remainder of
    // 2 and 3 into one group and ones with remainder of 1 and 0 into another, this will 
    // ensure the 2 sets sums are equal.
    ll intSum = n * (n + 1LL) / 2;
    std::vector<int> set1, set2;
    if (intSum % 2){
        cout << "NO" << endl;
        return 0;
    } else {
        cout << "Yes" << endl;

        if(n % 4 == 0){ // n = 4k
            for (int i = 1; i <= n; i++){
                if(i % 4 == 1 || i % 4 == 0)
                    set1.push_back(i);
                else set2.push_back(i);
            }
        }
        else{ // n = 4k + 3 -> n % 4 == 3
            for (int i = 1; i <= n; i++){
                if(i % 4 == 1 || i % 4 == 2)
                    set1.push_back(i);
                else set2.push_back(i);
            }
        }
    }
    cout << set1.size() << endl;
    for (int num : set1){
        cout << num << " ";
    }
    cout << endl;
    cout << set2.size() << endl;
    for (int num : set2){
        cout << num << " ";
    }
    cout << endl;


    return 0;
}