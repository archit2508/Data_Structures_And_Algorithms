#include <iostream>
#include <queue>
#include <cstring>
#include <string.h>
#include <vector>
using namespace std;

string key[] = {" ",".+@$","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
queue<string> q,q1;
vector<string> vec, vec1;
string searchIn[] = {"prateek", "sneha", "deepak", "arnav", "shikha", "palak",
                        "utkarsh", "divyam", "vidhi", "sparsh", "akku"};
                        
void comparison(string keycode, string insearch){
    //cout<<insearch<<" ";
    for(int i=0;i<insearch.size();i++){
        int j=0;
        if(insearch[i]==keycode[j]){
            int k=i;
            while(insearch[k]==keycode[j] && j<keycode.size()){
                j++;
                k++;
            }
            if(j==keycode.size()){
                vec1.push_back(insearch);
            }
        }
    }
}

void keypad(char in[], char out[], int i, int j, int &count){
    if(in[i]=='\0'){
        out[j]='\0';
        //cout<<out<<endl;
        count++;
        q.push(out);
        vec.push_back(out);
        return;
    }
    
    int currentdigit = in[i] - '0';
    if (currentdigit==0){
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
    
    if(strlen(input)>10){
        cout<<-1;
    }
    else keypad(input, output, 0, 0, count);
    
    //cout<<count<<endl;
    /*while(!q.empty()){
        str = q.front();
        cout<<str<<endl;
        q.pop();
    }*/
    
    
    for(int i=0;i<11;i++){
        //cout<<searchIn[i];
        for(int j=0;j<vec.size();j++){
            str = vec[j];
            comparison(str,searchIn[i]);
            //q.pop();
        }
    }
    
    //cout<<q1.size();
    
    for(int j=vec1.size()-1;j>=0;j--){
        str = vec1[j];
        cout<<str<<endl;
    }
    
    
    return 0;
}
