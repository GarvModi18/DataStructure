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

	if(nonZero > zeroCount)
		cout << "It is Not a Sparse Matrix"<<endl;
	else
		cout <<"It is a Sparse Matrix"<<endl;
}