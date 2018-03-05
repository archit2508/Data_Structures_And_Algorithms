#include <iostream>
using namespace std;

int unique_number1(int *a,int n){
    
    int ans=0;
    
    for(int i=0;i<n;i++){
        ans = ans ^ a[i];    
    }
    return ans;
}

void unique_number2(int *a,int n){
    
    int ans = unique_number1(a,n);
    int count=1;
    
    while(ans>0){
        if(ans&1){
            break;
        }
        else{
            count++;
        }
        ans = ans>>1;
    }
    
    int part1=0, part2=0;
    
    for(int i=0;i<n;i++){
        a[i] = a[i] >> (count-1);
        if(a[i]&1){
            part1 = part1^a[i];
        }
        else{
            part2 = part2^a[i];
        }
    }
    
    if(part1<part2){
        cout<<part1<<" "<<part2;
    }
    else{
        cout<<part2<<" "<<part1;
    }
}

int main() {
    
    int n;
    cin>>n;
    
    int a[100000];
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    unique_number2(a,n);
    
    return 0;
}
