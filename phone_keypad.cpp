#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

string key[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
queue<string> q;

void keypad(char in[], char out[], int i, int j, int &count){
    if(in[i]=='\0'){
        out[j]='\0';
        //cout<<out<<endl;
        count++;
        q.push(out);
        return;
    }
    
    int currentdigit = in[i] - '0';
    if (currentdigit==0||currentdigit==1){
        keypad(in, out, i+1, j, count);
    }
    
    for(int k=0; k<key[currentdigit].size(); k++){
        out[j] = key[currentdigit][k];
        keypad(in, out, i+1, j+1, count);
    }
}

int main() {
    
    char input[50], output[50];
    int count=0;
    string str;
    cin>>input;
    keypad(input, output, 0, 0, count);
    
    cout<<count<<endl;
    while(!q.empty()){
        str = q.front();
        cout<<str<<" ";
        q.pop();
    }
    
    return 0;
}
