#include<iostream>
using namespace std;

int *createArray(){
	int *a= new int[10];
	a[0]=a[1]=a[2]=5;
	cout<<"Address of a"<<a<<endl;
	return a;
}

int main(){
	int *p = createArray();
	cout<<"Address"<<p<<endl;
	for(int i = 0; i<3; i++){
		cout<<p[i]<<" ";
	}

	return 0;
}