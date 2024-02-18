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
			if(j==i && matrix[i][j] != 1) {
				flag--;
				break;
			}
			else if(matrix[i][j] != 0 && i!=j){
				flag--;
				break;
			}
		}
		if(flag !=1) break;
	}
	if(flag == 1 )cout<<"It is Identity matrix."<<endl;
	else cout<<"It is not Identity matrix."<<endl;
}