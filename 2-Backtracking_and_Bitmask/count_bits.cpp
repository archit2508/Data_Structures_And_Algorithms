#include <iostream>
using namespace std;

int countbits(int n){			// O(no. of bits)
    int ans = 0;
    while(n>0){
        if(n&1){
            ans++;
        }
        n = n>>1;
    }
    return ans;
}

int countbits1(int n){			// O(no. of setbits)
    int ans = 1;
    while(n=n&(n-1)){			// n & (n-1) removes last set bit
        ans++;
    }
    return ans;
}

int countbits2(int n){
    int ans = 0;
    while(n>0){
        ans++;
        int p = n&(-n);
        n = n - p;
    }
    return ans;
}

int main() {
    
    int n = 7;
    cout<<countbits2(n);
    
    return 0;
}
