#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

typedef long long ll;

/*
Your task is to place eight queens on a chessboard so that no two queens are attacking each other.
As an additional challenge, each square is either free or reserved, and you can only place queens
on the free squares. However, the reserved squares do not prevent queens from attacking each other.
How many possible ways are there to place the queens?

Input: the input has eight lines, and each of them has eight characters. Each square is either free(.)
or reserved(*).

Output: Print one integer: the number of ways you can place the queens.

Example:
Input:
........
........
..*.....
........
........
.....**.
...*....
........

Output:
65
*/
/*
Answer:

*/
bool isSafe(const std::vector<std::string>& board, int row, int col);
bool placeQueen(std::vector<std::string>& board, int row, int col){
    if(board[row][col] != '*' && isSafe(board,row,col)){
        board[row][col] = 'q';
        return true;
    }
    else{
        return false;
    }
}

bool isSafe(const std::vector<std::string>& board, int row, int col) {
    int n = board.size();
    
    // Check column
    for (int i = 0; i < n; ++i) {
        if (i != row && board[i][col] == 'q') {
            return false;
        }
    }

    // Check row
    for (int i = 0; i < n; ++i) {
        if (i != col && board[row][i] == 'q') {
            return false;
        }
    }

    // Check diagonals
    for (int i = -n; i <= n; ++i) {
        if (i != 0) {
            int diagRow1 = row + i, diagCol1 = col + i;
            int diagRow2 = row + i, diagCol2 = col - i;

            if (diagRow1 >= 0 && diagRow1 < n && diagCol1 >= 0 && diagCol1 < n && board[diagRow1][diagCol1] == 'q') {
                return false;
            }

            if (diagRow2 >= 0 && diagRow2 < n && diagCol2 >= 0 && diagCol2 < n && board[diagRow2][diagCol2] == 'q') {
                return false;
            }
        }
    }

    return true;
}

void removeQueen(std::vector<std::string>& board, int row, int col){
    if(board[row][col] == 'q'){
        board[row][col] = '.';
    }
}

int countQueens(std::vector<std::string>& board, int col) {
    if (col == board.size()) {
        return 1;  // Successfully placed all queens
    }
    int numWays = 0;
    for (int row = 0; row < board.size(); row++) {
        if (placeQueen(board, row, col)) {  // Check and place queen if possible
            numWays += countQueens(board, col + 1);  // Recur to place next queen
            removeQueen(board, row, col);  // Backtrack: remove queen and try next row
        }
    }
    return numWays;
}



int main(){
    std::vector<std::string> board(8);
    for( int i = 0; i < 8; i++ ){
        std::cin >> board[i];
    }

    std::cout << countQueens(board, 0) << std::endl;

    return 0;
}


/*
using namespace std;
#define ll long long
string s[8];
bool b[15];
int main(){
    for (int i = 0; i < 8; ++i)
        cin >> s[i];
    int p[8], ans = 0;
    iota(p,p+8,0);
    do{
        bool ok = 1;
        for (int i = 0; i < 8; ++i)
            ok&=s[i][p[i]] == '.';
        memset(b,0,15);
        for(int i = 0; i < 8; ++i){
            if(b[i+p[i]])
                ok = 0;
            b[i+p[i]] = 1;
        }
        memset(b,0,15);
        for(int i = 0; i < 8; ++i){
            if(b[i+7-p[i]])
                ok = 0;
            b[i+7-p[i]] = 1;
        }
        ans += ok;
    }while(next_permutation(p,p+8));
    cout << ans;
}

*/