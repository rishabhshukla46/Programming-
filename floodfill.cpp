#include<iostream>
#include<vector>

using namespace std;
static int count = 0;
void f(int sr, int sc, int dr, int dc, vector<vector<int>> & maze, string p){
   // cout<<sr<<sc<<dr<<dc<<endl;
    if(sc == dc && sr == dr){
        cout<<p<<endl;
        count++;
        return;
    }
    if(sc<0 || sr <0 || sc>maze[0].size()-1 || sr > maze.size()-1 || maze[sr][sc] == 1){
        return;
    }

    maze[sr][sc] = 1;
    f(sr+1, sc, dr, dc, maze, p+"D");
    f(sr, sc+1, dr, dc, maze, p+"R");
    f(sr-1, sc, dr, dc, maze, p+"U");
    f(sr, sc-1, dr, dc, maze, p+"L");
    maze[sr][sc] = 0;

    return;
}

int main(){
    //cout<<"1"<<endl;
    vector<vector<int>> maze {
                                {0, 1, 0, 0},
                                {0, 0, 0, 0},
                                {0, 1, 0, 0},
                                {0, 0, 1, 0},
                                            };
    //cout<<"2"<<endl;
    f(0,0,3,3,maze,"");
    cout<<"Total paths are "<<count<<endl;
    return 0;
}