#include <iostream>
using namespace std;

int knapsack(int wt[], int prices[], int n, int w){
    if(n==0||w==0){
        return 0;
    }
    
    int inc=0, exc=0;
    if(wt[n-1]>w){
        return knapsack(wt,prices,n-1,w);
    }
    inc = prices[n-1] + knapsack(wt,prices,n-1,w-wt[n-1]);
    exc = 0 + knapsack(wt,prices,n-1,w);
    
    return max(inc,exc);
}

int main() {
    
    int wt[] = {2,7,3,4};
    int prices[] = {5,20,100,10};
    int N=4;
    int W=11;
    
    int ans = knapsack(wt,prices,N,W);
    cout<<ans;
    
    return 0;
}
