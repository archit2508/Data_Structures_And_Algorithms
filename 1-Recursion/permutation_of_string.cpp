#include<iostream>
#include <set>
using namespace std;

set<string> s;

void printPermutation(char *input,int i){
	if(input[i]=='\0'){
		//cout<<input<<endl;
		string str(input);
		s.insert(str);
		return;
	}

	///Rec Case
	for(int j=i;input[j]!='\0';j++){
		swap(input[i],input[j]);
		printPermutation(input,i+1);
		//Backtracking - restore the original array
		swap(input[i],input[j]);
	}
}


int main(){
	char input[100];
	cin>>input;
	printPermutation(input,0);
	
	for(auto element:s){
	    cout<<element<<endl;
	}
	return 0;
}