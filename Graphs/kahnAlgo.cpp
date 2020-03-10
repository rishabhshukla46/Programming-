#include<iostream>
#include<vector>
#include<queue>
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
void kahnalgo(vector<vector<int>>& graph, int n){
    vector<int> indegree(n, 0);
    for(int i = 0; i < n; i++){
        for(int e : graph[i])
            indegree[e]++;
    }
    queue<int> que, ans;
    for(int i = 0; i < n; i++){
        if(indegree[i] == 0){
            que.push(i);
            ans.push(i);
        }
    }
    while(que.size() > 0){
        int temp = que.front();
        que.pop();
        for(int e : graph[temp]){
            indegree[e]--;
            if(indegree[e] == 0){
                que.push(e);
                ans.push(e);
            }
        }
    }
    if(ans.size() != n){
        cout<<"Not possible";
    }else{
        while(ans.size() != 0){
            cout<<ans.front()<<" ";
            ans.pop();
        }
    }
    cout<<endl;
}
int main(){
    int n = 6;
    vector<vector<int>>graph(n, vector<int>());
    creategraph(graph, n);
    display(graph, n);
    kahnalgo(graph, n);
    return 0;
}