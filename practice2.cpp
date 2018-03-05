#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void deletes(int a[], int p, int &n){
    int i;
    for(i=0; i<n; i++){
        if(a[i]==p){
            for(int j=i; j<n-i-1; j++){
                a[i]=a[i+1];
            }
            n--;
        }
    }
}
int deleter(int a[], int &n){
    long int temp=a[0], i;
    for(i=0; i<n-1; i++){
        a[i]=a[i+1];
    }
    n--;
    return temp;
}
int main()
{
    int n;
    int i, a[100000];
    int sum=0;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int m = sizeof(a)/sizeof(a[0]);
    sort(a, a+m);
    while(n>0){
        sum+=deleter(a, n);
        deletes(a, a[0]-1, n);
        deletes(a, a[0]+1, n);
    }
    cout<<sum;
    return 0;
}

