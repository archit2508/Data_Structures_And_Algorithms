#include <iostream>
using namespace std;
int main() {
    
    int a[10000], n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    int cs=0,ms=0;
    
    for(int i=0;i<n;i++){
        cs += a[i];
        if(cs<0){
            cs=0;
        }
        ms = max(cs,ms);
    }
    
    cout<<ms;
    
    return 0;
}
