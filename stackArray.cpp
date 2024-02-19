#include <iostream>
using namespace std;
int MAX=10;
int stack[10],TOP=-1;
void push(){
    int data;
    cout<<"Enter Num to push\n";
    cin>>data;

    if(TOP>=MAX-1){
        cout<<"Stack Overflow!!\n";
    }
    else{
        TOP++;
        stack[TOP]=data;
        cout<<"Data is Pushed!\n";
    }
}
void pop(){
    if(TOP!=-1){
    cout<<"Poped Element : "<<stack[TOP]<<endl;
    TOP--;
    }
    else{
        cout<<"Stack Underflow!!\n";
    }
}
void peek(){
    cout<<"Top Element : "<<stack[TOP]<<endl;
}
void display(){
    if(TOP==-1){
        cout<<"Stack Underflow!!\n"; 
    }
    else{
        cout<<"-------Stack-------\n";
        for (int i = TOP; i >= 0; i--)
        {
            cout<<"        "<<stack[i]<<"\n";
        }
        
    }
}
int main(){

    int choice;

    do{
        cout<<"------Menu------\n";
        cout<<"     1.PUSH\n     2.POP\n     3.PEEK\n     4.DISPLAY\n     5.EXIT\n";
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