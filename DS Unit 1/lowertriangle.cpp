#include <iostream>

using namespace std;


int main(){
	int rows,cols;

	cout <<"Enter Rows and Cols: ";
	cin >> rows>>cols;
	int matrix[rows][cols];
	
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cout<<"Enter Element("<<i<<","<<j<<"):";
			cin>>matrix[i][j];		
		}
	}
	int flag=1;
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			if(j>i && matrix[i][j] !=0) {
				flag--;
				break;
			}
		}
	}
	if(flag == 1 )cout<<"It is Lower triangular matrix."<<endl;
	else cout<<"It is not Lower triangular matrix."<<endl;
}