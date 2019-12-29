#include<iostream>
#include<vector>

using namespace std;

static int queens = 2;
void QiB(vector<bool> &boxes,int lq ,string p ){
    if(queens == 0){
        cout<<p<<endl;
        return;
    }

    if(queens < 0 || queens > 2){
        return;
    }

    for(int i =lq; i < boxes.size(); i++){
        if(boxes[i] != 1 && queens > 0){
            boxes[i] = 1;
            queens--;
            lq = i;
            QiB(boxes, lq,p+"Q"+to_string(2 - queens)+"B"+to_string(i)+" ");
            queens ++;
            boxes[i] =0;
        }
    }

    
}

int main(){
    vector<bool> boxes = {0, 0, 0, 0,};
    
    QiB(boxes, 0, "");
    return 0;
}