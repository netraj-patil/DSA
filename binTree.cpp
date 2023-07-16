#include<iostream>
#include<conio.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int d){
        data=d;
    }
};

struct Node* create(){
    int n,d;
    cout<<"Enter number of elements : ";
    cin>>n;
    struct Node *head;

    cout<<"\nEnter element at head : ";
    cin>>d;
    head = new Node(d);

    for(int i=1;i<n;i++){
        

        Node *node;
        node = head;
        cout<<"\n\nYou are at head : ";

        while(node != NULL)
        {
            cout<<"\npress 'r' to go right and 'l' to go left : ";
            char  ch;
            cin>>ch;
            
            if(ch=='r'||ch=='R'){
                node = node->right;
            }
            else if(ch=='l'||ch=='L'){
                node = node->left;
            }
            else{
                cout<<"\n You entered wrong input..........";
            }
        }

        cout<<"\nEnter the data : ";
        cin>>d;
        node = new Node(d);
        
    }

    return head;
}

void preOrder(struct Node *n){
    if(n != NULL){
        cout<<"\n"<<n->data;
        preOrder(n->left);
        preOrder(n->right);
    }
}

int main(){
    Node *head;
    head = create();
    preOrder(head);
    return 0;
}