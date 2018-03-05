#include <iostream>
#include <cstring>
using namespace std;

int minop(string s1, string s2, int i, int j){
    if(i==-1){
        return j+1;
    }
    
    if(j==-1){
        return i+1;
    }
    
    if(s1[i]==s2[j]){
        return minop(s1,s2,i-1,j-1);
    }
    
    int op1 = 1+minop(s1,s2,i-1,j-1);
    int op2 = 1+minop(s1,s2,i-1,j);
    int op3 = 1+minop(s1,s2,i,j-1);
    
    return min(op1,min(op2,op3));
}

int main() {
    
    string s1, s2;
    cin>>s1>>s2;
    
    int ans = minop(s1,s2,s1.size()-1,s2.size()-1);
    
    cout<<ans;
    
    return 0;
}
