#include<iostream>
#include<vector>

using namespace std;

int solve_suduko(vector<vector<int>>&suduko,vector<int> &calls,vector<int>&rows,vector<int>&col,vector<vector<int>>&matrix, int idx){
    if(idx == calls.size()){
        cout<<endl;
        for(vector<int> &arr : suduko){
            for(int ele : arr){
                cout<<ele<<" ";
            }
            cout<<endl;
        }
        return true;
    }   

    //bool res = false;
    int count = 0;
    int r = calls[idx] / 9;
    int c = calls[idx] % 9;
    for(int n = 1; n <= 9; n++){
        int mask = (1 << n);
        if((rows[r] & mask)==0 && (col[c] & mask)==0 && (matrix[r/3][c/3] & mask)==0 ){
            suduko[r][c] = n;
            rows[r] ^= mask;
            col[c] ^= mask;
            matrix[r/3][c/3] ^= mask;

            //res = res || solve_suduko(suduko, calls, rows, col, matrix, idx+1);
            count += solve_suduko(suduko, calls, rows, col, matrix, idx+1);

            suduko[r][c] = 0;
            rows[r] ^= mask;
            col[c] ^= mask;
            matrix[r/3][c/3] ^= mask;            
        }
    } 
    return count;
}

void preprocess(vector<vector<int>>&suduko,vector<int> &calls,vector<int>&rows,vector<int>&col,vector<vector<int>>&matrix){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(suduko[i][j] == 0){
                calls.push_back(i*9 + j);
            }
            else{
                int mask = 1 << suduko[i][j];
                rows[i] |= mask;
                col[j] |= mask;
                matrix[i/3][j/3] |= mask;
            }    
        }
    }
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
    
    vector<int> calls, rows(9,0), col(9,0);
    vector<vector<int>> matrix(3, vector<int>(3,0));

    preprocess(suduko, calls, rows, col, matrix);
    
    if(solve_suduko(suduko, calls, rows, col, matrix, 0)){
        cout<<"Solution exists"<<endl;
    }
    else{
        cout<<"No solution"<<endl;
    }

}