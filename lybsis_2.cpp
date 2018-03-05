#include <iostream>
using namespace std;

int prime(int num) {
   int i, flag;
   for (i = 2; i < num; i++) {
      if (num % i != 0)
         flag = 1;
      else {
         flag = 0;
         break;
      }
   }
 
   if (flag == 1 || num == 2)
      return (1);
   else
      return (0);
}

int main() {
    int num;
    int n=9;
    int spaces = n*2 - 2;
    
    for(int i=1;i<=n;i=i+2){
        
        for(int j=1;j<=spaces;j++){
            cout<<" ";
        }
        
        num = 1;
        for(int j=1;j<=i;j++){
            if(j<=(i/2)+1){
                num++;
                while(!prime(num)){
                    num++;
                }
                cout<<num<<" ";
            }
            else if(j>(i/2)+1){
                if(num!=3){num = num - 2;}
                else num--;
                while(!prime(num)){
                    num--;
                }
                cout<<num<<" ";
            }
        }
        
        spaces = spaces - 2;
        cout<<endl;
    }
}
