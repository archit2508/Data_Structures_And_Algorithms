#include <iostream>
using namespace std;

void insertionsort(int *a, int n){
    for(int i=1;i<n;i++){
        int key = a[i];
        int j = i-1;
        while(j>=0 && a[j]>key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

int main() {
    
    int n, m, a[1000];
    
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>m;
    
    insertionsort(a,n);
    
    int s,e;
    
    s=0;
    e=n-1;
    
    while(s<e){
        if(a[s]+a[e]==m){
            cout<<a[s]<<" and "<<a[e]<<endl;
            s++;
            e--;
        }
        else if(a[s]+a[e]<m){
            s++;
        }
        else{
            e--;
        }
    }
    return 0;
}
