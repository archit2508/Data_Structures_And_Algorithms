#include<iostream>
#include<set>
using namespace std;

set<string> s;

void code_of_string(char out[], int j, char in[], int i){
    
    if(in[i]=='\0'){
        out[j]='\0';
        string str(out);
        s.insert(str);
        return;
    }
    
    out[j]=(char)((in[i] - '0') + 96);
    code_of_string(out,j+1,in,i+1);
    
    if(in[i+1]!='\0')
    out[j]=(char)( (10*(in[i] - '0')) + (in[i+1] - '0') + 96 );
    if(out[j]>='a'&&out[j]<='z'){
        code_of_string(out,j+1,in,i+2);
    }
    else{
        return;
    }
    
}

int main(){
    char input[100], output[100];
    cin>>input;
    code_of_string(output,0,input,0);
    cout<<"[";
    for(auto i=s.begin();i!=s.end();i++){
        if(i==(--s.end())){
            cout<<(*i);
        }
        else
            cout<<(*i)<<", ";
    }
    cout<<"]";
    return 0;
}