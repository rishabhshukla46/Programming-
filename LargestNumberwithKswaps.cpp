#include<iostream>
#include<vector>

using namespace std;

void print_max(vector<int> intarr, int idx, int k){
    //cout<<"k = "<<k<<endl;
    if(k == 0){
        for(int i : intarr){
            cout<<i;
        }
        return;
    }
    int max = -1;
    int id;
    for(int i = idx; i < intarr.size(); i++){
        //cout<<"i = "<<i<<endl;
        if(intarr[i] > max){
            max = intarr[i];
            id = i;
        }
    }
    if(intarr[idx] < intarr[id]){
        //cout<<"swap"<<endl;
        int temp = intarr[idx];
        intarr[idx] = intarr[id];
        intarr[id] = temp;
    }
    
    print_max(intarr, idx+1, k-1);
    return;
}

int main(){
    int num, k;
    cin >> num;
    cin >> k;
    vector<int> arr;
    vector<int> intarr;
    while(num / 10 != 0){
        int temp = num % 10;
        arr.push_back(temp);
        num /= 10;
    }
    arr.push_back(num);    
    for(int i = arr.size() - 1; i >=0; i--){
        intarr.push_back(arr[i]);
    }

    print_max(intarr, 0, k);
    return 0;
}