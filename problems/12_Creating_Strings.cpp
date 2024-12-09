#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/*
Given a string, your task is to generate all different
strings that can be created using its characters.

Input: The only input line has a string of length n. Each character is between a-z;
Output:
First print and integer k: the number of strings.
Then print k lines: the strings in alphabetical order.

Example:
Input:
aabac
Output:
20
aaabc
aaacb
aabac
aabca
aacab
aacba
abaac
abaca
abcaa
acaab
acaba
baaac
baaca
bacaa
bcaaa
caaab
caaba
cabaa
cbaaa
*/

typedef long long ll;
typedef std::string String;

int main(){
    String s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<String> ans;
    do{
        ans.push_back(s);
    }while(next_permutation(s.begin(),s.end()));
    cout << ans.size() << "\n";
    for(String s : ans)
        cout << s << "\n";

    return 0;
}