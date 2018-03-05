#include<iostream>
using namespace std;

void merge(int a[], int x[], int y[], int s, int e){
	int i=s;
	int mid=(s+e)/2;
	int j=mid+1;
	int k=s;
	while(i<=mid && j<=e){
		if(x[i]<y[j]){
			a[k++]=x[i++];
		}
		else{
			a[k++]=y[j++];
		}
	}
	while(i<=mid){
		a[k++]=x[i++];
	}
	while(j<=e){
		a[k++]=y[j++];
	}
}

void mergesort(int a[], int s, int e){
	if(s==e||s>e){
		return;
	}
	int x[100], y[100];
	int mid=(s+e)/2;
	int i,j;
	for(i=s;i<=mid;i++){
		x[i]=a[i];
	}
	for(j=mid;j<=e;j++){
		y[j]=a[j];
	}
	mergesort(x,s,mid);
	mergesort(y,mid+1,e);
	merge(a,x,y,s,e);
}

int main(){
	int a[]={2,6,5,4,7,8,3,1,6,9};
	int n=sizeof(a)/sizeof(int);
	
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}

	cout<<endl;
	mergesort(a,0,n-1);

	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
