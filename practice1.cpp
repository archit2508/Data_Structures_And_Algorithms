#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Stack{
    public:
    int top;
    int st[1000];


        Stack(){
            top=-1;
        }
        void push(int x){
            if(top<1000){
                st[++top]=x;
            }
        }
        int pop(){
            return st[top--];
        }
        int isEmpty(){
            if(top==-1)
                return 1;
            else
                return 0;
        }
};

int main() {
    Stack stk1, stk2;
    int q, type, x;
    cin>>q;
    while(q--){
        cin>>type;
        switch(type){
            case 1:cin>>x;
                   stk1.push(x);
                   break;
            case 2:while(!stk1.isEmpty()){
                   stk2.push(stk1.pop());
                   }
                   stk2.top--;
                   while(stk2.top>=0){
                   stk1.push(stk2.pop());
                   }
                   break;
            case 3:while(stk1.top>=0){
                   stk2.push(stk1.pop());
                   }
                   cout<<endl<<stk2.st[stk2.top];
                   while(stk2.top>=0){
                   stk1.push(stk2.pop());
                   }
                   break;
        }
    }#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Stack{
    public:
    int top;
    int st[100000];


        Stack(){
            top=-1;
        }
        void push(int x){
            if(top<100000){
                st[++top]=x;
            }
        }
        int pop(){
            return st[top--];
        }
        int isEmpty(){
            if(top==-1)
                return 1;
            else
                return 0;
        }
};

int main() {
    Stack stk1, stk2;
    long long int q, x;
    int type;
    cin>>q;
    while(q--){
        cin>>type;
        switch(type){
            case 1:cin>>x;
                   stk1.push(x);
                   break;
            case 2:while(stk1.top>=0){
                   stk2.push(stk1.pop());
                   }
                   stk2.top--;
                   while(stk2.top>=0){
                   stk1.push(stk2.pop());
                   }
                   break;
            case 3:while(stk1.top>=0){
                   stk2.push(stk1.pop());
                   }
                   cout<<stk2.st[stk2.top]<<endl;
                   while(stk2.top>=0){
                   stk1.push(stk2.pop());
                   }
                   break;
        }
    }
    return 0;
}

    return 0;
}
