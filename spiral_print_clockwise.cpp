#include<iostream>
using namespace std;

void generateMatrix(int a[][10],int m,int n){
	int val = 1;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
			//cout<<a[i][j]<<" ";
		}
		//cout<<endl;
	}
}
void printMatrix(int a[][10],int m,int n){
	int val = 1;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			//a[i][j] = val++;
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

void spiralPrint(int a[][10],int m,int n){

	int startRow,endRow,startCol,endCol;
	startRow = startCol = 0;
	endRow = m;
	endCol = n;


	while(startRow<endRow && startCol<endCol){
		//Start row
		for(int i=startCol;i<endCol;i++){
			cout<<a[startRow][i]<<", ";
		}
		startRow++;
		//End Col
		for(int i=startRow;i<endRow;i++){
			cout<<a[i][endCol-1]<<", ";
		}
		endCol--;

		//Bottom Row if ER > SR
		if(endRow>startRow){
			for(int i=endCol-1;i>=startCol;i--){
				cout<<a[endRow-1][i]<<", ";
			}
			endRow--;

		}

		//Start Col
		if(startCol<endCol){
			for(int i=endRow-1;i>=startRow;i--){
				cout<<a[i][startCol]<<", ";
			}
			startCol++;
		}
	}
	cout<<"END";
}

int main(){

	int a[10][10];
	int m,n;
	cin>>m>>n;

	generateMatrix(a,m,n);
	//printMatrix(a,m,n);
	spiralPrint(a,m,n);
	
	return 0;
}