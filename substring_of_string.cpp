#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;

string str = "1234";

void substring(int start, int end){
    
    if(start==str.length()&&end==str.length()){
        return;
    }
    
    if(end==str.length()){
        substring(start+1,start+1);
    }
    else{
        for(int i=start;i<=end;i++){
            cout<<str[i];
        }
        cout<<endl;
        substring(start,end+1);
    }
}

int main() {
    
    substring(0,1);
    
    return 0;
}
