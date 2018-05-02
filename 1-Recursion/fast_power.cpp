#include <iostream>
using namespace std;

int power(int a, int n){
    if(n==0){
        return 1;
    }
    
    int temp = power(a,n/2);
    if(n%2){
        return temp*temp*a;
    }
    else
        return temp*temp;
}

int main() {
    
    int a;
    a = 2;
    cout<<power(a,5);
    
    return 0;
}
