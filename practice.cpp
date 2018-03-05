#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class stack{
    long int top;
    long long int st[100000];

    public:
        long long int maxm=0;
        stack(){
            top=-1;
        }
        void push(int x){
            if(top<100000){
                st[++top]=x;
            }
        }
        void pop(){
            if(top>-1)
                top--;
        }
        void maxstack(){
            maxm=st[top];
            long int temp=top;
            while(temp>=0){
                if(st[temp]>=maxm){
                    maxm=st[temp];
                }
                temp--;
            }
        }
};

int main() {
    long int N, type;
    long long int x;
    stack S;
    cin>>N;
    for(long int j=0;j<N;j++){
        cin>>type;
        switch(type){
            case 1: cin>>x;
                    S.push(x);
                    S.maxstack();
                    break;
            case 2: S.pop();
                    S.maxstack();
                    break;
            case 3: cout<<S.maxm<<"\n";
                    break;
        }
    }
    return 0;
}

