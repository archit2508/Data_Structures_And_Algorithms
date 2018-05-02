#include<iostream>
#include<ctime>
using namespace std;

bool rakhpaye(char a[][100], int row, int col, int n){
	//horizontal
	for(int i=0;i<n;i++){
		if(a[row][i]=='Q'){
			return false;
		}
	}
	//vertical
	for(int i=0;i<n;i++){
		if(a[i][col]=='Q'){
			return false;
		}
	}
	int i=row, j=col;
	while(i>=0&&j>=0){
		if(a[i][j]=='Q'){
			return false;
		}
		i--;
		j--;
	}
	i=row, j=col;
	while(i>=0&&j<n){
		if(a[i][j]=='Q'){
			return false;
		}
		i--;
		j++;
	}
	return true;
}

bool nqueen(char a[][100], int row, int n){
	if(row==n){
		for(int x=0;x<n;x++){
			for(int y=0;y<n;y++){
				cout<<a[x][y];
			}
			cout<<endl;
		}
	}

	for(int pos=0;pos<n;pos++){
		if(rakhpaye(a,row,pos,n)){
			a[row][pos]='Q';

			bool aglirakhpayekya=nqueen(a,row+1,n);
			if(aglirakhpayekya==true){
				return true;
			}
			a[row][pos]='.';
		}
	}
	return false;
}

int main(){

	char a[100][100];
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a[i][j]='.';
		}
	}

	for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<a[i][j];
			}
			cout<<endl;
		}
	clock_t  startTime = clock();
    nqueen(a,n,0);
    clock_t endTime = clock();
    cout<<"Algorithm took "<<endTime-startTime<<endl;

return 0;
}