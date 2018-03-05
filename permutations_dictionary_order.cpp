#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

queue<string> q;

int compare(string original, string rearranged, int i){
    if(original[i]=='\0'){
        return 0;
    }
    if(original[i]<rearranged[i]){
        return 1;
    }
    else if(original[i]==rearranged[i]){
        return compare(original, rearranged, i+1);
    }
    else return 0;
}

void dictionary(char in[], int i){
    if(in[i]=='\0'){
        //cout<<in<<endl;
        q.push(in);
        return;
    }
    
    for(int j=i; in[j]!='\0'; j++){
        swap(in[i],in[j]);
        dictionary(in, i+1);
        swap(in[i],in[j]);
    }
}

int main() {
    
    char input[50];
    string str;
    cin>>input;
    string orig = input;
    dictionary(input, 0);
    
    while(!q.empty()){
        str = q.front();
        int print = compare(orig, str, 0);
        //cout<<print<<endl;
        if(print){
            cout<<str<<endl;
            q.pop();
        }
        else
            q.pop();
    }
    
    return 0;
}
