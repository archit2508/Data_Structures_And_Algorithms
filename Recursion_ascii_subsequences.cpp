#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

stack<string> s;

void subsequences(char in[], int i, char out[], int j, int &count){
    if(in[i]=='\0'){
        out[j]='\0';
        cout<<out<<" ";
        string str(out);
        s.push(str);
        count++;
        return;
    }
    
    out[j]=in[i];
    subsequences(in,i+1,out,j+1,count);
    subsequences(in,i+1,out,j,count);
    
    int temp = in[i];
    string tempstr = "";
    while(temp>0){
        char c = temp%10 + 48;
        tempstr += c;
        temp = temp/10;
    }
    if(tempstr!=""){
        for(int a = tempstr.length()-1; a>=0; a--){
            out[j] = tempstr[a];
            j++;
        }
        subsequences(in,i+1,out,j,count);
    }
    else
        return;
    
}

int main() {
    char input[100], output[100];
    int counter=0, length=0;
    cin>>input;
    
    for(int s=0; input[s]!='\0'; s++){
        length++;
    }
    
    cout<<pow(3,length)<<endl;
    
    subsequences(input,0,output,0,counter);
    
    /*for(auto i=s.size();i>0;i--){
        cout<<" "<<s.top();
        s.pop();
    }*/
    return 0;
}
