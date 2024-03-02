#include <iostream>
using namespace std;
int queue[20],size=20;
int head=-1,rear=-1;
void Enqueue(){
    int num;
    cout<<"Enter data to be enterd\n";
    cin>>num;
    
    if(rear==size-1){
        cout<<"Queue Overflow!!\n";
    }
    else if(head==-1 && rear==-1){//When Empty
        head=rear=0;
        queue[rear]=num;
    }
    else{
        rear++;
        queue[rear]=num;
    }

}
void Dequeue(){
    if(head==-1 || head>rear){
        cout<<"Queue Underflow!!\n";
    }
    else{
        cout<<"Removed Element : "<<queue[head]<<endl;
        head++;
    }
}
void peek(){
      if(head==-1 || head>rear){
        cout<<"Queue Underflow!!\n";
    }
    else{
         cout<<"Head Element : "<<queue[head]<<endl;
    }
}
void display(){

    int counter=head;

    if(head==-1 || head>rear){
        cout<<"Queue Underflow!!\n";
    }
    else{

        while(counter<=rear){
        cout<<" "<<queue[counter]<<" ";
        counter++;
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