#include <iostream>
using namespace std;
class node {
public:
int data;
node *left;
node *right;
};
node *tree=NULL;
void insert(){
    int val;
    node *newnode=new node();
    node *parentnode,*currentnode;
    newnode->left=NULL;
    newnode->right=NULL;

    cout<<"Enter data to be entered\n";
    cin>>val;
    newnode->data=val;

    if(tree==NULL){
        tree=newnode;
    }
    else{
        parentnode=NULL;
        currentnode=tree;

        while(currentnode!=NULL){
            parentnode=currentnode;

            if(val<currentnode->data){
                currentnode=currentnode->left;
            }
            else{
                currentnode=currentnode->right;
            }
        }
        if(val<parentnode->data){
            parentnode->left=newnode;
        }
        else{
            parentnode->right=newnode;
        }
    }

}
void inorder(node *tree){
    if(tree!=NULL){
        inorder(tree->left);
        cout<<" "<<tree->data<<" ";
        inorder(tree->right);
    }
}

void preorder(node *tree){
    if(tree!=NULL){
        cout<<" "<<tree->data<<" ";
        preorder(tree->left);
        preorder(tree->right);
    }
}

void postorder(node *tree){
    if(tree!=NULL){
        postorder(tree->left);
        postorder(tree->right);
        cout<<" "<<tree->data<<" ";
    }
}
int main(){
    int choice;
    do{
        cout<<"\n1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.Exit\n";
        cin>>choice;

        if(choice==1){
            insert();
        }
        else if(choice==2){
        inorder(tree);
        }
        else if(choice==3){
            preorder(tree);
        }
        else if(choice==4){
            postorder(tree);
        }
        else if(choice==5){
            cout<<"\nExiting\n";
        }
        else{
            cout<<"Invlid Choice\n";
        }
    }
    while(choice !=5);
}
