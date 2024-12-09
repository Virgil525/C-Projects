#include <iostream>
#include <set>
/*
You are given a list of n integers, and your task is to calculate the number of distinct values
in the list.
Input:
the first line of input has an integer n: the number of values
The second line has n integers x1,x2,...,xn
Output:
Print one integer: the number of distinct values.

sample input:
5
2 3 2 2 3
sample output:
2
*/

using namespace std;

int main(){
    int n;
    cin >> n;
    // set contains unique values :D
    set<int> s;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        s.insert(a);
    }
    cout << s.size();

    return 0;
}