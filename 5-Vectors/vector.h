#include <iostream>
using namespace std;
class vector{
    int *a;
    int cs;
    int ms;
    
public:
    vector(int ds=4){
        a = new int[ds];
        cs = 0;
        ms = ds;
    }
    
    vector(vector &v){
        a = new int[v.ms];
        cs = 0;
        ms = v.ms;
        
        for(int i=0;i<v.cs;i++){
            push_back(v[i]);
        }
    }
    
    void push_back(int d){
        if(cs==ms){
            int *olda = a;
            a = new int[2*ms];
            ms = 2*ms;
            
            for(int i=0;i<cs;i++){
                a[i] = old[i];
            }
            
            delete []olda;
        }
        
        a[cs] = d;
        cs++;
    }
    
    void pop_back(){
        if(cs>0){
            cs--;
        }
    }
    
    bool isEmpty(){
        if(cs==0){
            return true;
        }
        return false;
    }
    
    int maxSize(){
        return ms;
    }
    
    int size(){
        return cs;
    }
    
    int& operator[](vector v, int i){
        return a[i];
    }
}