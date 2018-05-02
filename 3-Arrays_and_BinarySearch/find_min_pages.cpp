#include <iostream>
using namespace std;

bool isValid(int *a, int n, int students, int current_ans){
    
    int s=1;
    int currently_allotted = 0;
    
    for(int i=0;i<n;i++){
        
        if(a[i]>current_ans){
            return false;
        }
        
        if(currently_allotted + a[i] <= current_ans){
            currently_allotted += a[i];
        }
        else{
            s++;
            if(s>students){
                return false;
            }
            currently_allotted = a[i];
        }
    }
    
    return true;
}

int findminpages(int *a, int n, int students){
    
    int s = 0;
    int e = 100;
    
    int mid;
    int ans = INT8_MAX;
    
    while(s<=e){
        mid = (s+e)/2;
        if(isValid(a,n,students,mid)){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    
    return ans;
}

int main() {
    
    int a[] = {10,20,30,40};
    int n = sizeof(a)/sizeof(int);
    int s = 2;
    
    cout<<findminpages(a,n,s);
    
    return 0;
}
