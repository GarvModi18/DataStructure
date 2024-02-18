#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node *next;
};

int main(){
	Node *head=new Node();
	int length;
	cout <<"Enter Linked List Length:";
	cin >> length;
	Node *currentNode = head;
	for(int i=0;i<length;i++){
		cout<<"Enter Data for Node" << i+1;
		cin >> currentNode->data;
		currentNode->next = new Node();
		if(i != length -1){
			currentNode = currentNode->next;
		}
	};
	currentNode = head;

	for(int i=0;i<length;i++){
		cout<<currentNode->data<<endl;
		currentNode = currentNode->next;	
	}
}