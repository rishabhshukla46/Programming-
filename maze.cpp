#include<iostream>
using namespace std;


void maze_m(int sr, int sc, int dr, int dc, string p){
    if(sr == dr && sc == dc){
        cout<<p<<endl;
    }


    //horizontal call
    for( int i = 1; i <= dc - sc; i++){
        maze_m( sr, sc+i, dr, dc, p+"H"+to_string(i));
    }

    //vertical call
    for( int i = 1; i <= dr - sr; i++){
        maze_m( sr+i, sc, dr, dc, p+"V"+to_string(i));
    }

    //diagonal call
    for( int i = 1; i <= dc - sc && i <= dr-sr; i++){
        maze_m( sr+i, sc+i, dr, dc, p+"V"+to_string(i));
    }
}

void maze_d(int sr, int sc, int dr, int dc, string p){
    if(sr == dr && sc == dc){
        cout<<p<<endl;
        return;
    }
    if(sc>dc || sr>dr){
        return;
    }

    //diagnol call
    maze_d(sr+1, sc+1, dr, dc, p+"D");
    
    //horizontal call
    maze_d( sr, sc+1, dr, dc, p+"H");

    //vertical call
    maze_d( sr+1, sc, dr, dc, p+"V");
}


void maze(int sr, int sc, int dr, int dc, string p){
    if(sr == dr && sc == dc){
        cout<<p<<endl;
        return;
    }
    if(sc>dc || sr>dr){
        return;
    }

    //horizontal call
    maze( sr, sc+1, dr, dc, p+"H");

    //vertical call
    maze( sr+1, sc, dr, dc, p+"V");
}

int main(){
    //maze(0, 0, 3, 3, "");
    //maze_d(0, 0, 2, 2, "");
    maze_m(0,0,2,2,"");
    return 0;
}