#include <iostream>
#include <memory>
#include <algorithm>

/*
There are n children who want to go to a Ferris wheel, and your task is to find a gondola for each child.
Each gondola may have one or two children in it, and in addition, the total weight in a gondola
may not exceed x. You know the weight of every child.
What is the minimum number of gondolas needed for the children?

Input:
The first input line contains two integers n and x: the number of children and the maximum allowed weight.
The next line cotains n integers p1,p2,...,pn: the weight of each child.
Output:
Print one integer: the minimum number of gondolas.

Sample input:
4 10
7 2 3 9
Sample output:
3
*/

using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    std::unique_ptr<int[]> weights = std::make_unique<int[]>(n);
    for(int i =0; i < n; i++){
        cin>>weights[i];
    }
    sort(weights.get(),weights.get()+n);

    int ans = 0; 
    int newLimit = x;  
    for(int i = 0, j = n-1; i < n -1; i++ ){
        while(i < j&& weights[i]+weights[j] >x)
            j--;
        if(i >= j)
            break;
        ans++;
        j--;
    }
    cout << n - ans;

    return 0;
}
