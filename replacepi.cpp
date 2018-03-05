#include <iostream>
using namespace std;

void pi(char in[], int i=0){
    if(in[i+3]=='\0'){
        return;
    }
    
    if(in[i]=='3'&&in[i+1]=='.'&&in[i+2]=='1'&&in[i+3]=='4'){
        in[i]='p';
        in[i+1]='i';
        int j=i+2;
        while(in[j+2]){
            in[j]=in[j+2];
            j++;
        }
        in[j]='\0';
        pi(in, i+2);
    }
    else{
        pi(in, i+1);
    }
}

int main() {
    
    int n;
    char input[1000];
    cin>>n;
    int t=n;
    while(n>0){
        if(n<t){
            cin.getline(input, 1000);
        }
        else{
            cin.get();
            cin.getline(input, 1000);
        }
        
        pi(input);
        cout<<input<<endl; 
        n--;
    }
    
    return 0;
}
