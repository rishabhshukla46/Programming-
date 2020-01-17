#include<iostream>
#include<vector>

using namespace std;

bool Isvalid(vector<vector<int>>& chess, int x, int y){
    if(x<0 || y<0 || x>=chess.size() || y>= chess[0].size() || chess[x][y] != 0){
        return false;
    }
    return true;
}

bool solve(vector<vector<int>>& chess, vector<vector<int>>& dir, int sr, int sc, int moves){
    if(moves == chess.size() * chess[0].size()){
        return true;
    }
    bool res = false;
    for(int i = 0; i < dir.size(); i++){
        int x = sr + dir[i][0];
        int y = sc + dir[i][1];
        if(Isvalid(chess, x ,y)){
            chess[x][y] = moves;
            res = res || solve(chess, dir, x, y, moves+1);
            chess[x][y] = 0; 
        }
    }
    return res;
} 

int main(){
    int N, sr, sc;
    cin>>N;
    cin>>sr;
    cin>>sc;
    vector<vector<int>> chess(N, vector<int>(N, 0));
    vector<vector<int>> dir = {{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, -1}, {2, 1}, {-1, -2}, {1, -2}};

    if(solve(chess, dir, sr, sc, 1)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}
