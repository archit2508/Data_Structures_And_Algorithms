#include <iostream>
using namespace std;

int search(int a[],long int n,long int m){
    int s=0;
    int e=n-1;
    int mid;
    
    while(s<=e){
        mid = (s+e)/2;
        
        if(a[mid]==m){
            return mid;
        }
        else if(m<a[mid]){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    
    return -1;
}

int main() {
    
    long int n, m;
    cin>>n;
    
    int *a = new int(sizeof(int)*n);
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    cin>>m;
    
    int pos = search(a,n,m);
    cout<<pos;
    
    return 0;
}
