#include<iostream>
#include<vector>

using namespace std;

bool Isvalid(vector<vector<bool>> &board, int x, int y){
    if(x<0 || y<0 || x >= board.size() || y >= board[0].size() || board[x][y] == true){
        return false;
    }
    return true;
}

vector<string> floodfill(int sr, int sc, int dr, int dc, vector<vector<bool>> &board, vector<string> &path, vector<vector<int>> &dir){
    if(sr == dr && sc == dc){
        vector<string> base;
        base.push_back("");
        return base;
    }
    board[sr][sc] = true;
    vector<string> myans;

    for(int i = 0; i < dir.size(); i++){
        int x = sr + dir[i][0];
        int y = sc + dir[i][1];
        if(Isvalid(board, x, y)){
            vector<string> ans = (floodfill(x, y, dr, dc, board, path, dir));
            for(string s: ans){
                myans.push_back(path[i] + s);
            }
        }
    }
    board[sr][sc] = false;
    return myans;
}

int main(){
    vector<vector<bool>> board(3, vector<bool>(3, false));
    vector<string> path = { "U", "d1", "R", "d2", "D", "d3", "L", "d4"};
    vector<vector<int>> dir = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

    vector<string> answer = floodfill(0, 0, 2, 2, board, path, dir);
    for(string s : answer){
        cout<<s<<endl;
    }

    return 0;
}