#include<iostream>
using namespace std;

int max(node *root){
	if(root==NULL){
		return INT_MIN;
	}
	
	int d = root->data;
	int l = max(root->left);
	int r = max(root->right);
	
	if(l>d){
		d = l;
	}
	if(r>d){
		d = r;
	}
	return d;
}



int main(){
	return 0;
}