#include<iostream>
#include<vector>

using namespace std;

static int count = 0; 

void cc_p(vector<int> & d, int sum, string p){
    if( sum == 0){
        cout<<p<<endl;
        count++;
        return;
    }

    if(sum < 0){
        return;
    }
    
    for( int i =0; i < d.size(); i++){
        if( sum > 0){
            //lp = i;
            cc_p(d, sum - d[i], p+to_string(d[i]));
        }
    }
}

void cc_c(vector<int> & d, int sum, int lp, string p){
    if( sum == 0){
        cout<<p<<endl;
        return;
    }

    if(sum < 0){
        return;
    }
    
    for( int i =lp; i < d.size(); i++){
        if( sum > 0){
            lp = i;
            cc_c(d, sum - d[i], lp, p+to_string(d[i]));
        }
    }
}

int main(){
    vector<int> denom = { 2, 3, 5, 6};
    //cc_p(denom, 10, "");
    cc_c(denom, 10, 0, "");
    return 0;
}