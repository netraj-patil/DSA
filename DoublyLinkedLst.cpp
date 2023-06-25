#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;

struct Node{
    int data;
    struct Node* prev=NULL;
    struct Node* next=NULL;
};

void add(Node* ptr,int d){
    while (ptr->next != NULL)
    {
        ptr=ptr->next;
    }

    struct Node* n=new Node;
    n->data=d;
    n->prev=ptr;
    ptr->next=n;
}


void insert(struct Node* ptr,int p,int d){
    for(int i=1;i<p-1;i++){
        if(ptr->next==NULL){
            std::cout<<"Not enough space";
            return;
        }
        ptr=ptr->next;
    }

    Node* node=new Node;
    node->data=d;

    if(ptr->next=NULL){
        ptr->next=node;
        node->prev=ptr;
        return;
    }

    //Node* a=ptr->next;

    node->next=ptr->next;
    node->prev=ptr;
    ptr->next=node;
    node->next->prev = node;
}

void Delete(struct Node* ptr,int p){
    for(int i=1;i<p-1;i++){
        if(ptr->next==NULL){
            std::cout<<"Nothing to delete";
            return;
        }
        ptr=ptr->next;
    }

    if(ptr->next=NULL){
        std::cout<<"Nothing to delete";
        return;
    }

    struct Node* a;
    a=ptr->next;

    ptr->next=a->next;
    //delete a;
    a=ptr->next;
    a->prev=ptr;
}



void show(struct Node* ptr){
    do
    {
        std::cout<<"\n"<<ptr->data;
        ptr=ptr->next;
    }while (ptr != NULL);
}

int main(){
    struct Node* head=new Node;
    head->data=43;

    add(head,34);
    add(head,54);
    add(head,6);
    add(head,4);
    add(head,834);
    add(head,354);
    add(head,87);
    add(head,94);
    add(head,87);

    insert(head,4,65);
    Delete(head,7);

    show(head);

    return 0;
}