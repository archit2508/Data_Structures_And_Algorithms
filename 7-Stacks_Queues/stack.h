#ifndef MyStack
#define MyStack

#include <vector>
using namespace std;

template<typename T>

public class Stack{
    vector<T> vec;
    T x;
    
    public:
        void push(T data){
            vec.push_back(data);
        }
        void pop(){
            vec.pop_back();
        }
        T top(){
            int n = vec.size();
            return vec[n-1];
        }
        bool IsEmpty(){
            return vec.size()==0;
        }
}

#endif