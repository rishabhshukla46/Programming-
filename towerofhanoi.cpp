#include<iostream>
using namespace std;

void toh(string src, string des, string help, int n){
    if(n == 0){
        return;
    }
    toh(src, help, des, n-1);
    cout << "Move "<< n <<"th disc from "<<src<<" to "<< des<<endl;
    toh(help, des, src, n-1 );
    return;
}


int main(){
    toh("A", "B", "C", 4);
    return 1;
}