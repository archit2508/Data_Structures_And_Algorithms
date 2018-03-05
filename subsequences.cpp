#include<iostream>
#include<set>
#include<cstring>
using namespace std;

set<string> s;

void subsequences(char input[], int i, char output[], int j){
	if(input[i]=='\0'){
		output[j]='\0';

		string str(output);
		s.insert(str);
		return;
	}

	output[j]=input[i];
	subsequences(input,i+1,output,j+1);
	subsequences(input,i+1,output,j);
}

int main(){

	char str[]="abc";
	char out[10];

	subsequences(str,0,out,0);

	for(auto it=s.begin();it!=s.end();it++){
		cout<<(*it)<<endl;
	}
	return 0;
}