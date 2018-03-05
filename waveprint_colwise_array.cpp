#include <iostream>
using namespace std;
int main() {
    
    int m, n, a[10][10];
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    
    int col=0;
    
    while(col<n){
        if(col%2==0){
            for(int i=0;i<m;i++){
                cout<<a[i][col]<<", ";
            }
        }
        else{
            for(int j=m-1;j>=0;j--){
                cout<<a[j][col]<<", ";
            }
        }
        col++;
    }
    
    cout<<"END";
    
    return 0;
}
