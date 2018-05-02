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

int unique_number3(int *a, int n){
    int sum;
    int x;
    int result=0;
    
    for(int i=0;i<32;i++){
        sum=0;
        x = 1<<i;
        
        for(int j=0;j<n;j++){
            if(a[j]&x){
                sum++;
            }
        }
        if(sum%3){
            result += x;
        }
    }
    
    return result;
}

int unique_number3_alt(int *a, int n){
    int ones=0;
    int twos=0;
    int common_bits_mask;
    
    for(int i=0;i<n;i++){
        twos |= (ones&a[i]);
        ones ^= a[i];
        
        common_bits_mask = ~(ones&twos);
        ones &= common_bits_mask;
        twos &= common_bits_mask;
    }
    
    return ones;
}

int main() {
    
    int n;
    cin>>n;
    
    int a[100000];
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    cout<<unique_number3_alt(a,n);
    
    return 0;
}
