#ifndef MyQueue
#define MyQueue

public class Queue{
    int cs, ms;
    int front, rear;
    int *a;
    
    public:
        Queue(int ds=5;){
            cs = 0;
            ms = ds;
            fornt = 0;
            rear = ms-1;
            a = new int[ms];
        } 
        
        void push(int data){
            if(cs<ms){
                rear = (rear+1)%ms;
                a[rear] = data;
                cs++;
            }
        }
        void pop(){
            front = (front+1)%ms;
            cs--;
        }
        bool IsEmpty(){
            return cs==0;
        }
        int front(){
            return a[front];
        }
        
}

#endif