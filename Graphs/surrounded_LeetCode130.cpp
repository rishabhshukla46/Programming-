#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<char>> &board, int r, int c, int n, int m){
        if(board[r][c] != 'O')return;
        board[r][c] = '#';
        if(r-1 >= 0) dfs(board, r-1, c, n, m);
        if(r+1 < n) dfs(board, r+1, c, n, m);
        if(c-1 >= 0) dfs(board, r, c-1, n, m);
        if(c+1 < m) dfs(board, r, c+1, n, m);
        return;
    }
void solve(vector<vector<char>> &board) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O')
                dfs(board, i, 0, n, m);
            if(board[i][m-1] == 'O')
                dfs(board, m-1, 0, n, m);
        }
        for(int i = 0; i < m; i++){
            if(board[0][i] == 'O')
                dfs(board, 0, i, n, m);
            if(board[n-1][i] == 'O')
                dfs(board, n-1, i, n, m);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O')board[i][j] = 'X';
                if(board[i][j] == '#')board[i][j] = 'O';
            }
        }
    }
    int main(){
        vector<vector<char>> board = {{'X','X','X','X'}, {'X','O','O','X'}, {'X','X','O','X'}, {'X','O','X','X'}};
        solve(board);
        return 0;
    }
