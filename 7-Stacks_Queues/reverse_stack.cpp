#include <iostream>
#include <stack>
using namespace std;

void print(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}

void pushtobottom(stack<int> &s, int data){
    if(s.empty()){
        s.push(data);
        return;
    }
    
    int temp = s.top();
    s.pop();
    pushtobottom(s,data);
    s.push(temp);
}

void reverse(stack<int> &s){
    if(s.empty()){
        return;
    }
    
    int temp = s.top();
    s.pop();
    
    reverse(s);
    pushtobottom(s,temp);
}

int main() {
    stack<int> s;
	
	for(int i=1;i<=5;i++){
		s.push(i);
	}
	//While the stack is not empty
	print(s);

	reverse(s);

	print(s);

	return 0;
}
