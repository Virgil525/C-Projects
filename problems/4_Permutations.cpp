#include <iostream>

/*
a permutation of integers 0,1,2,...,n is called beautiful if there ar e no adjacent 
elements whose difference is 1. Given n, construct a beautiful permutation if such a 
permutation exists.
*/

using namespace std;
int main(){
    int n;
    cin >> n;

    // Edge cases || no solution
    if(n==1){
        cout << 1;
        return 0;
    }
    if(n==2 || n==3){
        cout << "No solution";
        return 0;
    }
    
    for(int i = 1; i <= n ; i+=2)
            cout<<i<<" ";
    for(int i = 0; i <= n; i+=2)
            cout<<i<<" ";
    
    // Even and odd cases
    
    if(n%2 == 0) {
        for(int i = 1; i <= n - 1; i+=2)
            cout<<i<<" ";
        for(int i = 0; i <= n; i+=2)
            cout<<i<<" ";
    }  else {
        for(int i = n-1; i >= 0; i-=2)
            cout<<i<<" ";
        for(int i =n; i >= 0; i-=2){
            cout << i << " ";
        }
    }
    
    return 0;
}
