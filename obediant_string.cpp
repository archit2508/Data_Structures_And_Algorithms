#include <iostream>
#include <string>
using namespace std;

bool obediant(string in, int i){
    if(in[0]=='\0'){
        return false;
    }
    
    else if(in[i]=='\0'){
        return true;
    }
    
    else if(in[i]=='a'){
        obediant(in,i+1);
    }
    else if(in[i]=='b'&&in[i+1]=='b'){
        obediant(in,i+2);
    }
    else
    return false;
}

int main() {
    string input;
    cin>>input;
    if(obediant(input,0)==true){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}
