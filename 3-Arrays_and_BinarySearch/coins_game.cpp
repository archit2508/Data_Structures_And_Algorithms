#include <iostream>
using namespace std;

int mat[10][10] = {0};

int coinsgame(int a[], int i, int j){
    if(i>j){
        return 0;
    }
    
    if(mat[i][j]!=0){
        return mat[i][j];
    }
    
    int partialans = coinsgame(a,i+1,j-1);
    int firstcoin = a[i] + min(coinsgame(a,i+2,j),partialans);
    int lastcoin = a[j] + min(coinsgame(a,i,j-2),partialans);
    
    int ans = max(firstcoin,lastcoin);
    
    mat[i][j] = ans;
    
    return ans;
}

int main() {
    
    int a[] = {1,4,3,2,18,3};
    int n = 6;
    
    cout<<coinsgame(a,0,n-1);
    
    return 0;
}
