#include<iostream>
#include<conio.h>
using namespace std;

struct Node{
    int data;
    struct Node* next = NULL;
};

void create(struct Node* ptr,int d){
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = new Node;
    ptr=ptr->next;
    ptr->data=d;
}

void insert(struct Node* ptr,int p,int d){      //here head node has number 1
    for(int i=1;i<p-1;i++){
        if(ptr==NULL){
            cout<<"\nCannot insert! Not enough element";
            return;
        }
        ptr=ptr->next;
    }
    struct Node* n = new Node;
    n->data=d;
    n->next=ptr->next;
    ptr->next=n;
}

void Delete(struct Node* ptr,int p){
    for(int i=1;i<p-1;i++){
        if(ptr==NULL){
            cout<<"\nCannot delete! Not enough element";
            return;
        }
        ptr=ptr->next;
    }
    Node* node;
    node = ptr->next;
    ptr->next = node->next;
    delete node;
}

void display(struct Node* ptr){
    while (ptr!= NULL)
    {
        std::cout<<"\n"<<ptr->data;
        ptr=ptr->next;
    }
    
}

int main()
{
    Node* head =new Node;
    head->data=56;

    int p,d;

    create(head,39);
    create(head,34);
    create(head,367);
    create(head,56);
    create(head,3);
    create(head,67);
    create(head,78);
    create(head,64);
    create(head,86);
    create(head,65);
    create(head,21);
    create(head,78);
    create(head,98);
    create(head,68);
    create(head,23);
    create(head,12);
    create(head,5);
    create(head,8);

    std::cout<<"\n"<<"-----------------------------";
    display(head);
    std::cout<<"\n======================================================";
    std::cout<<"\nEnter position at which u want to insert an node : ";
    std::cin>>p;
    std::cout<<"\nEnter data with which u want to insert an node : ";
    std::cin>>d;
    insert(head,p,d);

    std::cout<<"\nEnter position at which u want to delete a node : ";
    std::cin>>p;
    Delete(head,p);

    std::cout<<"\n=====********************************************====";
    display(head);
    return 0;
}