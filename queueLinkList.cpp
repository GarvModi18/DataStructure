//LINEAR QUEUE USING LINK LIST
#include <iostream>
using namespace std;
class node {
public:
    int data;
    node *next;
};
node *head=NULL,*rear=NULL;

void Enqueue(){
    int num;
    cout<<"Enter data tobe entered\n";
    cin>>num;

    node *newnode=new node();
    newnode->data=num;

    if(head==NULL && rear==NULL){
        head=rear=newnode;
        newnode->next=NULL;
    }
    else{
        rear->next=newnode;
        newnode->next=NULL;
        rear=newnode;
    }

}
void Dequeue(){

    if(head==NULL || rear==NULL){
        cout<<"Queue Underflow!!\n";
    }
    else{
        cout<<"Removed Element : "<<head->data<<endl;
        node *ptr=head;
        head=head->next;
        free(ptr);
    }

}
void peek(){
     if(head==NULL || rear==NULL){
        cout<<"Queue Underflow!!\n";
    }
    else{
     cout<<"Head Element : "<<head->data<<endl;

    }
}
void display(){

    if(head==NULL || rear==NULL){
        cout<<"Queue Underflow!!\n";
    }
    else{
        node *ptr=head;
        while(ptr!=NULL){
            cout<<" "<<ptr->data<<" ";
            ptr=ptr->next;
        }
    cout<<endl;    
    }
    
}
int main(){

    
int choice;

    do{
        cout<<"------Menu------\n";
        cout<<"    1.Enqueue\n    2.Dequeue\n    3.PEEK\n    4.DISPLAY\n    5.EXIT\n";
        cin>>choice;
        switch (choice)
        {
        case 1:
            Enqueue();
            break;
        
        case 2:
            Dequeue();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            cout<<"------EXIT------\n";
            break;    

        default:
            cout<<"Invalid Choice \n";
            break;
        }
    }while(choice!=5);

    return 0;
}