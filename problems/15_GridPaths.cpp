#include <iostream>
#include <vector>
#include <string>
#include <climits> // For LLONG_MAX
/*
There are 88418 paths in a 7x7 grid from the upper-left square to the 
lower left square. Each path corresponds to a 48_character dexcription consisting of 
characters D(down), U(up), L(Left) and R(right).

You are given a description of a path which may also contain characters ? (anydirection).
Your task is to calculate the number of paths that match the description

The only input line has a 48-character string of characters
?, D, U, L and R

Output
Print one integer: the total number of paths
*/
using namespace std;
#define ll long long;

// sample input: ??????R??????U??????????????????????????LD????D?
// result: 201
// Function to check if the position is valid

std::string s;
bool visited[7][7];
int ans = 0;
bool isValid(int x, int y){
    return x>=0 && x<7 && y >=0 && y < 7 && !visited[y][x];
}

void dfs(int x, int y, int steps = 0){
    if( x == 6 && y == 6 && steps == 48){
        ans++;
        return;
    }
    visited[y][x] = 1;
    if(s[steps]=='?' || s[steps] == 'L'){
        if(x&&!visited[y][x-1]) {
            if(!(!isValid(y,x-2)&&isValid(y+1,x-1)&&isValid(y-1,x-1)))
                dfs(y,x-1,steps+1);
        }
    }
    if(s[steps]=='?' || s[steps] == 'R'){
        if(x<6&&!visited[y][x+1]) {
            if(!(!isValid(y,x+2)&&isValid(y+1,x+1)&&isValid(y-1,x+1)))
                dfs(y,x+1,steps+1);
        }
    }
    if(s[steps]=='?' || s[steps] == 'U'){
        if(y&&!visited[y-1][x]) {
            if(!(!isValid(y-2,x)&&isValid(y-1,x-1)&&isValid(y-1,x+1)))
                dfs(y-1,x,steps+1);
        }
    }
    if(s[steps]=='?' || s[steps] == 'D'){
        if(y<6&&!visited[y+1][x]) {
            if(!(!isValid(y+2,x)&&isValid(y+1,x-1)&&isValid(y+1,x+1)))
                dfs(y+1,x,steps+1);
        }
    }
    visited[y][x] = 0;
}

int main(){
    std::cin >> s;
    dfs(0,0);
    std::cout << ans;
    ss
    return 0;
}
