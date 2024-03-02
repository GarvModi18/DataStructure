#include <iostream>
using namespace std;
int queue[10],MAX=10,front=-1,rear=-1;

void Enqueue(){//From Rear

    int num; 
    cout<<"Enter Data\n";
    cin>>num;

    if(front==-1 || rear==-1){//When empty
        front=rear=0;
        queue[rear]=num;
    }
    else if(rear==MAX-1 && front==0){//When full from behind and no space at index 0
        cout<<"Queue Overflow!!\n";
    }
    else if(rear==MAX-1 && front>0){//When full from behind but has space at index 0
        rear=0;
        queue[rear]=num;
    }
    else if(rear==front-1){//When rear has come at begin/starting of queue and has no space between rear and front
        cout<<"Queue Overflow!!\n";
    }
    else{//Normal conditions
        rear++;
        queue[rear]=num;
    }

}

void Dequeue(){//From Front

    if(front==-1 || rear==-1){//If Empty
        cout<<"Queue Underflow!!\n";
    }
    else if(front==MAX-1 && rear!=front){//When front is at last Index
        cout<<"Dequeued Element : "<<queue[front]<<endl;
        front=0;
    }
    else if(front==rear){//When theres only 1 Element in queue
        cout<<"Dequeued Element : "<<queue[front]<<endl;
        front=rear=-1;
    }
    else{
        cout<<"Dequeued Element : "<<queue[front]<<endl;
        front++;
    }

}
void Peek(){
    cout<<"\nHead Element : "<<queue[front]<<endl;
}
void Display(){

    if(front==-1 || rear==-1){
        cout<<"Queue Underflow!!\n";
    }
    else if(front<rear){
        int i=front;

        cout<<"---------Queue---------\n";
        while(i<=rear){
            cout<<" "<<queue[i]<<" ";
            i++;
        }       
        cout<<endl; 
        cout<<"-----------------------\n";
    }
    else if(front>rear){
        int i=front;

        cout<<"---------Queue---------\n";
        while(i<=MAX-1){//Elements : Front-End(index Max-1)
            cout<<" "<<queue[i]<<" ";
            i++;
        }  
        i=0;
        while(i<=rear){//Elements : Start(index 0)-Rear
            cout<<" "<<queue[i]<<" ";
            i++;
        }
        cout<<endl; 
        cout<<"-----------------------\n";

    }
    else{//Front==Rear OR When theres Only 1 Element
        cout<<"---------Queue---------\n";
        cout<<" "<<queue[rear]<<" \n";
        cout<<"-----------------------\n";     
    }
}
int main(){

    
    int choice;

    do{
        cout<<"------Menu------\n";
        cout<<"   1.Enqueue\n   2.Dequeue\n   3.PEEK\n   4.DISPLAY\n   5.EXIT\n";
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
            Peek();
            break;

        case 4:
            Display();
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