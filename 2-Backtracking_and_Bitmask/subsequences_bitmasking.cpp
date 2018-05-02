#include <iostream>
using namespace std;

void filter(char *in, int n){
    int k = 0;
    
    while(n>0){
        if(n&1){
            cout<<in[k];
        }
        k++;
        n = n>>1;
    }
}

int main() {
    
    char input[] = "abc";
    int len = 3;
    
    for(int i=0;i<(1<<len);i++){
        filter(input,i);
        cout<<endl;
    }
    
    return 0;
}
