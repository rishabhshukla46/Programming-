#include<iostream>
using namespace std;


void path_ladders(int src, int des, int ladders[], string p){
    
    if(src>des){
        return;
    }
    
    if(src == des){
        //cout<<"base case hit";
        cout<<p<<endl;
        return;
    }

    if(src == 0){
        path_ladders(1, des, ladders, p+to_string(1));
        path_ladders(1, des, ladders, p+to_string(6));
    }
    
    if(src!= 0){
        for(int i = 1; i <=6; i++){
            if(src+i <= 16 && ladders[src+i]!=0){
                path_ladders(src+ladders[src+i], des, ladders, p+to_string(src+i)+"--"+to_string(ladders[src+i]));
            }
            else{
                path_ladders(src+i, des, ladders,p+to_string(i));
            }
               
        }
    }
    
}

/*void path_16(int src, int des, string p){
    
    if(src>des){
        return;
    }
    
    if(src == des){
        //cout<<"base case hit";
        cout<<p<<endl;
        return;
    }

    if(src == 0){
        path_16(1, des, p+to_string(1));
        path_16(1, des, p+to_string(6));
    }
    else{
        for(int i = 1; i <=6; i++){
         path_16(src+i, des, p+to_string(i));   
        }
    }
    
}*/
/*void path (int src, int des, string p){
    
    if(src>des){
        return;
    }
    
    if(src == des){
        //cout<<"base case hit";
        cout<<p<<endl;
        return;
    }
    
    //cout<<"before loop";
    for(int i = 1; i <=6; i++){
        int check = src+i;
        //if (check <= des){
         path(src+i, des, p+to_string(i));   
      //  }
        
    }
}*/

int main(){
    //path_16(0, 10, "");
    int ladders[16] = {0, 0, 0, 13, 11, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    path_ladders(0, 15, ladders, "");
    //cout<<"ending"<<endl;
    return 0;
}