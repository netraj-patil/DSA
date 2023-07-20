#include<iostream>
#include<conio.h>
#include<queue>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

void insert(struct Node* root, int data){
    queue<struct Node*> q;
    struct Node *temp;
    struct Node *node;

    node = (struct Node*)malloc(sizeof(struct Node));
    node->left=node->right=NULL;
    node->data=data;

    if(!node){
        cout<<"\nmemory error";
        return;
    }

    if(!root){
        root = node;
        return;
    }

    q.push(root);


    while(!q.empty()){
        temp= q.front();
        q.pop();

        if(temp->left != NULL){
            q.push(temp->left);
        }
        else{
            temp->left = node;
            return;
        }
        if(temp->right != NULL){
            q.push(temp->right);
        }
        else{
            temp->right = node;
            return;
        }
    }
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
    insert(head,32);
    insert(head,23);
    insert(head,45);
    insert(head,1);
    insert(head,2);
    insert(head,78);
    insert(head,87);
    insert(head,6);
    insert(head,98);
    
    preOrder(head);
    return 0;
}