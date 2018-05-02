#include <iostream>
using namespace std;
int main() {
    
    int a[] = {1,-2,3,4,6,-5,8,1,-4,2};
    int n = 10,cs=0,ms=0;
    
    for(int i=0;i<n;i++){
        cs += a[i];
        if(cs<0){cs = 0;}
        ms = max(cs,ms);
        
    }
    
    cout<<ms;
    
    return 0;
}
