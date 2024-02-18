#include <iostream>

using namespace std;


int main(){
	int rows,cols;

	cout <<"Enter Rows and Cols: ";
	cin >> rows>>cols;
	int matrix[rows][cols];
	int zeroCount=0;
	for(int i=0;i<rows;i++)
		for(int j=0;j<cols;j++){
			cout<<"Enter Element:";
			cin>>matrix[i][j];
			if(matrix[i][j] ==0)zeroCount++;
		}
	int nonZero = (rows*cols) - zeroCount;

	if(nonZero > zeroCount){
		cout << "It is Not a Sparse Matrix"<<endl;
		return 0;
	}

	int repre[nonZero][3];
	int count=0;
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			if(matrix[i][j] != 0){
				repre[count][0] = i;
				repre[count][1] = j;
				repre[count][2] = matrix[i][j];
				count++;
			}
		}
	}
	
	for(int i=0;i<rows;i++){
		for(int j =0;j<rows;j++){
			cout<<matrix[i][j] <<" ";
		}
		cout<<endl;
	}
	cout<<"Row Index:";
	for(int i =0;i<nonZero;i++)
		cout<<repre[i][0]<<" ";
	cout<<endl;
	cout<<"Col Index: ";
	for(int i =0;i<nonZero;i++)
		cout<<repre[i][1]<<" ";
	cout<<endl;
	cout<<"Value: ";
	for(int i =0;i<nonZero;i++)
		cout<<repre[i][2]<<" ";
	cout<<endl;

}