#include <iostream>
using namespace std;
//INCOMPLETE INSERT DELETE ALL OPERATIONS 
class node{
public: 
    int data;
    node* next; 
};
node *head=NULL;
node *rear=NULL;
void insert(){
    node *newnode=new node();
    cout<<"Enter data to insert\n";
    cin>>newnode->data;

    if(head==NULL){
        head=rear=newnode;
        rear->next=head;//NULL
    }
    else{
       newnode->next=head;
       rear->next=newnode;
       rear=newnode;
    }

}
void remove(){
    int nodeNo,i=1;
    cout<<"Enter no of Node to Delete\n";
    cin>>nodeNo;//3

    node *preptr=NULL,*ptr=head;

    do{
        if(i==nodeNo){
            if(i==1){//if HEAD
                head=ptr->next;
                rear->next=head;
                free(ptr);
                break;
            }
           
            else if(ptr->next!=head){
                preptr->next=ptr->next;
                free(ptr);
                break;
            }    
        }
        i++;
        preptr=ptr;
        ptr=ptr->next;

    }while(ptr->next!=head);

    //For removing last element 
    if(i==nodeNo){
            if(ptr==rear){
                preptr->next=head;
                rear=preptr;
                free(ptr);
            }
        }

}
void display(){

    node *ptr=head;
    while(ptr->next!=head){
        cout<<" "<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<" "<<ptr->data<<" ";

    
}
int main(){

    int choice;

    do{
        cout<<"\n1.Insert\n2.Remove\n3.Display\n4.Exit\n";
        cin>>choice;

        if(choice==1){
            insert();
        }
        else if(choice==2){
        remove();
        }
        else if(choice==3){
            display();
        }
        else{
            cout<<"Invalid Choice\n";
        }
    }
    while(choice !=4);

}