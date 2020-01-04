#include<iostream>
#include<vector>

using namespace std;

bool Isvalid(vector<vector<int>> &suduko, int row, int col, int num){
    for(int i = 0; i < 9; i++){
        if(suduko[row][i] == num) return false;
        if(suduko[i][col] == num) return false;
        int r = (row/3)*3;
        int c = (col/3)*3;
        for(int m = 0; m < 3; m++){
            for(int n = 0; n < 3; n++){
                if(suduko[r+m][c+n] == num) return false;
            }
        }
    }

    return true;
}



int solve_suduko(vector<vector<int>> &suduko, vector<int> &calls,int idx){
    if(idx == calls.size()){
        cout<<endl;
        for(vector<int> &arr : suduko){
            for(int ele : arr){
                cout<<ele<<" ";
            }
            cout<<endl;
        }
        return 1;
    }

    int count = 0;
    int row = calls[idx]/9;
    int col = calls[idx]%9;

    if(suduko[row][col] == 0){
        for(int n = 1; n <=9; n++){
            if(Isvalid(suduko, row, col, n)){
                suduko[row][col] = n;
                count += solve_suduko(suduko, calls,idx+1);
                suduko[row][col] = 0;
            }
        }
    }
    else{
        count += solve_suduko(suduko, calls,idx+1);
    }




    return count;
}

bool suduko_solution(vector<vector<int>> &suduko, vector<int> &calls,int idx){
    if(idx == calls.size()){
        for(vector<int> &arr : suduko){
            for(int ele : arr){
                cout<<ele<<" ";
            }
            cout<<endl;
        }
        return true;
    }

    bool res = false;
    int row = calls[idx]/9;
    int col = calls[idx]%9;

    for(int n = 0; n <= 9; n++){
        if(Isvalid(suduko, row, col, n)){
           suduko[row][col] = n;
           res = res || suduko_solution(suduko, calls, idx+1);
           if(res) return res;
            suduko[row][col] = 0;
        }
    }
    return res;

}

int main(){
    vector<vector<int>> suduko = {{0, 0, 6, 0, 0, 8, 0, 0, 0},
                                 {5, 2, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 8, 7, 0, 0, 0, 0, 3, 1},
                                 {0, 0, 3, 0, 1, 0, 0, 8, 0},
                                 {9, 0, 0, 8, 6, 3, 0, 0, 5},
                                 {0, 5, 0, 0, 9, 0, 6, 0, 0},
                                 {1, 3, 0, 0, 0, 0, 2, 5, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 7, 4},
                                 {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    vector<int> calls;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(suduko[i][j] == 0){
                calls.push_back(i*9 + j);
            }    
        }
    }

    //int ans = solve_suduko(suduko,calls, 0);
    //cout<<"Total solutions are "<< ans << endl;
    if(suduko_solution(suduko, calls, 0)){
        cout<<"Solution exists"<<endl;
    }
    else{
        cout<<"No solution"<<endl;
    }
    return 0;
}