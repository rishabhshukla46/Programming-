#include<iostream>
#include<vector>

using namespace std;

bool IsValid(vector<vector<bool>> &maze, int x, int y){
    if(x<0 || y<0 || x >= maze.size() || y >= maze[0].size() || maze[x][y]){
        return false;
    }
    return true;
}
vector<string> ff(int sr, int sc, int dr, int dc, vector<vector<bool>> &maze, vector<vector<int>> &dir, vector<string> &path){
    if(sr == dr && sc == dc){
        vector<string> base;
        base.push_back("");
        return base;
    }

    vector<string>myans;
    maze[sr][sc] = true;

    for(int i = 0; i < dir.size(); i++){
        int x = sr + dir[i][0];
        int y = sc + dir[i][1];

        if(IsValid(maze, x, y)){
            vector<string> ans = ff(x, y, dr, dc, maze, dir, path);

            for(string s: ans){
                myans.push_back(path[i]+ s);
            }
        }
    }
        maze[sr][sc] = false;

        return myans;
    }





int main(){
    vector<vector<bool>> maze(4, vector<bool>(5, false));
    vector<vector<int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};
    vector<string>path = {"L", "U", "R", "D"};

    vector<string> ans = ff(0, 0, 3, 3, maze, dir, path);
 
    for(string s: ans){
        cout<<s<<endl;
    }
    return 0;
}