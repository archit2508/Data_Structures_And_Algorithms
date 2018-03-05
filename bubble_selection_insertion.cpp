#include <iostream>
using namespace std;

void bubblesort(int *a, int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
}

void insertionsort(int *a, int n){
    for(int i=1;i<n;i++){
        int key = a[i];
        int j = i-1;
        while(j>=0 && a[j]>key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

void selectionsort(int *a, int n){
    for(int i=0;i<n-1;i++){
        int mindex = i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[mindex]){
                mindex = j;
            }
        }
        swap(a[mindex],a[i]);
    }
}

int main() {
    
    long int n;
    cin>>n;
    //int *a = new int(sizeof(int)*n);
    int a[100000000];
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    selectionsort(a,n);
    
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
    
    return 0;
}
