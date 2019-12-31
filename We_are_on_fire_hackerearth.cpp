#include<iostream>
#include<vector>

using namespace std;

void print_map(vector<vector<bool>> &Map){
    cout<<endl;
    for (int i = 0; i < Map.size(); i++) { 
        for (int j = 0; j < Map[i].size(); j++) 
            cout << Map[i][j] << " "; 
        cout << endl; 
    }
}

void attack( int sr, int sc, vector<vector<bool>> &Map, vector<vector<int>> &adj){
    if(sr<0 | sc<0 || sr >= Map.size() || sc >= Map[0].size() || Map[sr][sc]== true){
        return;
    }
    else{
        Map[sr][sc] = true;
        for(int i = 0; i < adj.size(); i++){
            int x = sr + adj[i][0];
            int y = sc + adj[i][1];

            attack(x, y, Map, adj);
        }
    }
    return;
}

int main(){
    vector<vector<bool>> Map = {{0, 0, 0},
                                {0, 1, 0},
                                {0, 0, 0}};
    vector<vector<int>> adj = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

    print_map(Map);
    attack(0, 0, Map, adj);
    print_map(Map);
}