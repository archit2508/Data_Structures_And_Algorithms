#include <iostream>
using namespace std;

char a[1001][1001];
int sol[1001][1001];

bool ratinmaze(int i, int j, int m, int n){
    
    if(i==m-1&&j==n-1){
        sol[i][j] = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
        
    sol[i][j] = 1;
    
    if(i+1<m&&a[i+1][j]=='O'){
        if(ratinmaze(i+1,j,m,n)){
            return true;
        }
    }
    
    if(j+1<n&&a[i][j+1]=='O'){
        if(ratinmaze(i,j+1,m,n)){
            return true;
        }
    }
    
    sol[i][j] = 0;
    a[i][j] = 'X';
    return false;
}

int main() {
    
    int m, n;
    cin>>m>>n;
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    if(a[0][0]=='X'||!ratinmaze(0,0,m,n))
        cout<<-1;
    return 0;
}
