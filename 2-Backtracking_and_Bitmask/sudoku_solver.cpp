#include <iostream>

using namespace std;

bool isSafe(int mat[][9], int i, int j, int k, int n){
    
    for(int m=0;m<n;m++){
        if(mat[m][j]==k||mat[i][m]==k){
            return false;
        }
    }    
    
    int sn = 3;
    int si = (i/3)*3;
    int sj = (j/3)*3;
    
    for(int a=si;a<si+3;a++){
        for(int b=sj;b<sj+3;b++){
            if(mat[a][b]==k){
                return false;
            }
        }
    }
    
    return true;
}

bool sudokusolver(int mat[][9], int i, int j, int n){
    if(i==n){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    
    if(j==n){
        return sudokusolver(mat,i+1,0,n);
    }
    
    if(mat[i][j]!=0){
        return sudokusolver(mat,i,j+1,n);
    }
    
    for(int k=1;k<=n;k++){
        if(isSafe(mat,i,j,k,n)){
            mat[i][j] = k;
        
            bool isitokay = sudokusolver(mat,i,j+1,n);
            if(isitokay){
                return true;
            }
        }
    }
    
    mat[i][j] = 0;
    return false;
}

int main() {
    
    int mat[9][9] = 
        {{5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}};
        
    int n = 9;
    
    if(!sudokusolver(mat,0,0,n)){
        cout<<"No solution exists";
    }
    
    return 0;
}
