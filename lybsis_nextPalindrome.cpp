#include <iostream>
using namespace std;

bool ALL9(int a[], int n){
    int flag=0;
    for(int i=0;i<n;i++){
        if(a[i]!=9){
            flag = 1;
            break;
        }
    }
    
    if(flag==0)
        return true;
    else
        return false;
}

void nextPalindromeUtil(int a[],int n){
    int mid = n/2;
    int i = mid - 1;
    int j = (n%2) ? mid+1 : mid;
    bool leftsmaller = false;
    
    while(i>=0&&a[i]==a[j]){
        i--;
        j++;
    }
    
    if(i<0 || a[i]<a[j]){
        leftsmaller = true;
    }
    
    while(i>=0){
        a[j]=a[i];
        i--;
        j++;
    }
    
    if(leftsmaller==true){
        int carry = 1;
        i = mid - 1;
        
        if(n%2 == 1){
            a[mid]+=carry;
            carry = a[mid]/10;
            a[mid] = a[mid]%10;
            j = mid + 1;
        }
        else
            j = mid;
            
        while(i>=0){
            a[i] += carry;
            carry = a[i]/10;
            a[i] %= 10;
            a[j++] = a[i--];
        }
    }
}

void nextPalindrome(int a[],int n){
    if(ALL9(a,n)){
        cout<<"1 ";
        for(int j=1;j<n;j++)cout<<"0 ";
        cout<<"1";
    }
    else
        nextPalindromeUtil(a,n);
}

void print(int a[], int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}

int main() {
    
    int a[] = {9, 9, 1, 8, 7, 9, 7, 8, 3, 2, 2};
    int n = 11;
    
    nextPalindrome(a,n);
    print(a,n);
    
    return 0;
}
