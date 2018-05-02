#include <iostream>
using namespace std;

int unique_one(int *arr, int n){
    int ans = 0;
    for(int i=0;i<n;i++){
        ans ^= arr[i];
    }
    return ans;
}

void unique_two_twice(int *arr, int n){
    int temp = unique_one(arr,n);
    int count = 0;
    while(temp>0){
        if(temp&1){
            break;
        }
        else
            count++;
            
        temp = temp>>1;
    }
    
    int part1 = 0, part2 = 0;
    
    for(int i=0;i<n;i++){
        int k = arr[i];
        k = k>>(count);
        if(k&1){
            part1 ^= arr[i];
        }
        else
            part2 ^= arr[i];
    }
    
    cout<<part1<<" "<<part2;
}

int unique_one_thrice(int *arr, int n){
    int bits[64] = {0};
    
    for(int i=0;i<n;i++){
        int k = arr[i];
        int j=0;
        while(k>0){
            bits[j++] += k&1;
            k >>= 1;
        }
    }
    
    int ans = 0;
    int p=1;
    
    for(int i=0;i<64;i++){
        bits[i] %= 3;
        ans += bits[i]*p;
        p <<= 1;
    }
    
    return ans;
}

int main() {
    
    int arr[] = {1,1,2,2,9,6};
    int n = 6;
    unique_two_twice(arr,n);
    
    return 0;
}
