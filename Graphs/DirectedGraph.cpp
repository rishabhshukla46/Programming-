#include<iostream>
#include<vector>
using namespace std;


void creategraph(vector<vector<int>>& graph, int n){
    graph[5].push_back(0);
    graph[5].push_back(2);
    graph[4].push_back(0);
    graph[4].push_back(1);
    graph[2].push_back(3);
    graph[3].push_back(1);
}
void display(vector<vector<int>>& graph, int n){
    for(int i = 0; i < n; i++){
        cout<<i<<"--> ";
        for(int e : graph[i])
            cout<<e<<", ";
        cout<<endl;
    }
}

void topoDfs(vector<vector<int>>& graph, int n, vector<bool>& vis, vector<int>& stck, int i){
    vis[i] = true;
    for(int e : graph[i]){
        if(!vis[e])
            topoDfs(graph, n, vis, stck, e);
    }
    stck.push_back(i);
}
bool isCycle(vector<vector<int>>& graph, int n, vector<bool>& vis, int i, vector<bool>& cycle){
    vis[i] = cycle[i] = true;
    bool res = false;
    for(int e : graph[i]){
        if(!vis[e] && !res)
            res = res || isCycle(graph, n, vis, e, cycle);
        else if(cycle[e])
            return true;
    }
    cycle[i] = false;
    return res;
}

int main(){
    int n = 6;
    vector<vector<int>>graph(n, vector<int>());
    creategraph(graph, n);
    display(graph, n);
    vector<bool> vis(n, false);
    vector<int> stck;
    vector<bool> cycle(n, false);
    for(int i = 0; i < n; i++){
        if(!vis[i])
            if(isCycle(graph, n, vis, i, cycle))
                cout<<"Cycle is there"<<endl;
    }
    return 0;
}