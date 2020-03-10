#include<iostream>
#include<vector>
#include<queue>
using namespace std;


void addedge(vector<vector<int>>& graph, int u, int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}
void createGraph(vector<vector<int>>& graph, int n){
    addedge(graph, 0, 1);
    addedge(graph, 0, 3);
    addedge(graph, 1, 2);
    addedge(graph, 2, 3);
    addedge(graph, 3, 4);
    addedge(graph, 4, 5);
    addedge(graph, 4, 6);
    addedge(graph, 5, 6);
}
void display(vector<vector<int>>& graph, int n){
    for(int i = 0; i < n; i++){
        cout<<i<<"--> ";
        for(int e : graph[i])
            cout<<e<<", ";
        cout<<endl;
    }
}
void bfs(vector<vector<int>>& graph, int n, int start, vector<bool>& vis){
    queue<int> que;
    que.push(start);
    while(que.size() > 0){
        int size = que.size();
        while(size > 0){
            int vtx = que.front();
            cout<<vtx<<" ";
            que.pop();
            vis[vtx] = true;
            for(int e : graph[vtx]){
                if(vis[e] != true){
                    que.push(e);
                    vis[e] = true;
                }
            }
            size--;
        }
    }
}
void dfs(vector<vector<int>>& graph, int n, int start, vector<bool>& vis){
    cout<<start<<" ";
    vis[start] = true;
    for(int e : graph[start]){
        if(!vis[e]){
            vis[e] = true;
            dfs(graph, n, e, vis);
        }
    }
}
void removeE(vector<vector<int>>& graph, int u, int v){
    int i = 0;
    for(int e : graph[u]){
        if(e == v)
            graph[u].erase(graph[u].begin() + i);
        i++;
    }
    i = 0;
    for(int e : graph[v]){
        if(e == u)
            graph[v].erase(graph[v].begin() + i);
        i++;
    }
}
void removeV(vector<vector<int>>& graph, int u){
    for(int i = graph[u].size()-1; i >=0; i--){
        removeE(graph, u, graph[u][i]);
    }
}
bool path(vector<vector<int>>& graph, vector<bool>& vis, int src, int des, string ans){
    if(src == des){
        cout<<ans<<endl;
        return true;
    }
    bool res = false;
    for(int e : graph[src]){
        if(!vis[e]){
            vis[e] = true;
            res = res ||  path(graph, vis, e, des, ans+to_string(e)+" ");
            vis[e] = false;
        }
    }
    return res;
}
bool Hpath(vector<vector<int>>& graph, int n, vector<bool>& vis, int src, int count, string ans){
    if(count == n -1){
        cout<<ans<<endl;
        //return true;
    }
    bool res = false;
    vis[src] = true;
    for(int e : graph[src]){
        if(!vis[e]){
            res = res || Hpath(graph, n, vis, e, count+1, ans+to_string(e)+" ");
        }
    }
    vis[src] = false;
    return res;
}
int main(){
    int n = 7;
    vector<vector<int>> graph(n, vector<int>());
    createGraph(graph, n);
    display(graph, n);
    vector<bool> vis(n, false);
    //dfs(graph, n, 0, vis);
    //removeV(graph, 2);
    //if(!Hpath(graph, n, vis, 0, 0, to_string(0)+" ")) cout<<"No path";
    
    return 0;
}