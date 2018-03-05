#include<iostream>
using namespace std;

int power(int a, int b){

	if(b==0){
		return 1;
	}
	
	int value = power(a,b/2);
	value *= value;

	if(b&1){
		return a*value;
	}

	return value;
}

int main(){

	int a, b;
	cin>>a>>b;

	cout<<power(a,b)<<endl;

	return 0;
}