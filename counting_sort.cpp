#include <iostream>
using namespace std;
int main() {
    
    long long int n;
    cin>>n;
    
    int a[1000000];
    int ans[1000000];
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    int count[1000000] = {0};
    
    for(int i=0;i<n;i++){
        count[a[i]]++;
    }
    
    for(int i=1;i<1000000;i++){
        count[i] += count[i-1];
    }
    
    for(int i=0;i<n;i++){
        ans[count[a[i]]-1] = a[i];
        count[a[i]]--;
    }
    
    for(int i=0;i<n;i++){
        a[i] = ans[i];
        cout<<a[i]<<" ";
    }
    
    return 0;
}
