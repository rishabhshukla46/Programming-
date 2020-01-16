#include<iostream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;

void solve(string str, int idx, int k, string& p){
    if(k == 0){
        return;
    }

    int max = -1;
    int id;
    for(int i = idx; i < str.length(); i++){
        if(str[i] > max){
            max = str[i];
            id = i;
        }
    }
    swap(str[idx], str[id]);
    p = str;
    solve(str, idx+1, k-1, p);
    swap(str[idx], str[id]);
    return;
}

int main(){
    string str;
    cin>>str;
    int k;
    cin>>k;
    string p = "";
    solve(str, 0, k, p);
    cout<<p<<endl;

    return 0;
}
