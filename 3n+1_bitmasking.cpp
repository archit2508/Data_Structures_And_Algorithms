#include <iostream>
using namespace std;

int bitmasking(int *a, int n){
    int bit[64] = {0};
    
    for(int j=0;j<n;j++){
        int i=0;
        int n = a[j];
        while(n>0){
            bit[i] += n&1;
            i++;
            n >>= 1;
        }
    }
    
    int p=1;
    int ans=0;
    for(int i=0;i<64;i++){
        bit[i] %= 3;
        ans += bit[i]*p;
        p <<= 1;
    }
    
    return ans;
}

int main() {
    
    int a[] = {2,2,2,3,3,3,4,4,4,5,6,6,6,7,7,7};
    int n = sizeof(a)/sizeof(int);
    
    cout<<bitmasking(a,n);
    return 0;
}
