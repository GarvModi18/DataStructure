#include <iostream>
using namespace std;
class node{
public:    
    int data;
    node *next;
};
node *TOP=NULL;//a GLOBAL pointer to point at Top
void push(){
    int num;

    cout<<"Enter Data to Push\n";
    cin>>num;

    node* newnode=new node();
    newnode->data=num;

    if(TOP==NULL){
        newnode->next=NULL;
        TOP=newnode;
    }
    else{
        newnode->next=TOP;
        TOP=newnode;
    }

}
void pop(){

    if(TOP==NULL){
        cout<<"Stack Underflow!!\n";
    }
    else{
        node *ptr=TOP;
        cout<<"Poped Element : "<<ptr->data<<endl;
        TOP=TOP->next;
        free(ptr);
    }
}
void peek(){
    cout<<"Top Element : "<<TOP->data<<endl;

}
void display(){
    if(TOP==NULL){
        cout<<"Stack Underflow!!\n";
    }
    else{
        node *ptr=TOP;
        cout<<"-------Stack-------\n";
        while(ptr!=NULL){
            cout<<"        "<<ptr->data<<"\n"; 
            ptr=ptr->next;
        }
    }

}
int main(){
 int choice;

    do{
        cout<<"------Menu------\n";
        cout<<"    1.PUSH\n    2.POP\n    3.PEEK\n    4.DISPLAY\n    5.EXIT\n";
        cin>>choice;
        switch (choice)
        {
        case 1:
            push();
            break;
        
        case 2:
            pop();
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