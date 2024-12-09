#include <iostream>
#include <algorithm>
#include <string>
typedef long long ll;

/*
Given a string, your task is to reorder its letters in such a way
that is becomes a palindrome (i.e., it reads the same forwards and backwards).

Input: The only inpuit line has a string of length n consisting of characters A-Z

Output: Print a palindrome consisting of the characters of the original string. 
You may print any valid solution. If there are no solutions, print "NO SOLUTION".
*/

using namespace std;
typedef std::string String;

int main(){
    String inp;
    cin >> inp;
    int c[26] = {}, c1 = 0;
    for(char d : inp)
        ++c[d - 'A'];
    for(int i = 0; i < 26; i++)
        c1 += c[i]&1;
    if(c1>1) {
        cout << "NO SOLUTION";
        return 0;
    }
    String t;
    for(int i = 0; i < 26; i++)
        if(c[i]&1^1)
            for(int j=0; j < c[i]/2; ++j)
                t += (char)('A'+i);
    cout << t;
    for(int i = 0; i < 26; i++)
        if(c[i]&1)
            for(int j = 0; j < c[i]; j++)
                cout << (char)('A'+i);
    reverse(t.begin(),t.end());
    cout << t << endl;

    return 0;
}