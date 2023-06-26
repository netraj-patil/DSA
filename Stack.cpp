#include<iostream>
#include<conio.h>
using namespace std;

struct Stack
{
    int size;
    int top;
    int *arr;
};

bool isEmpty(Stack* s){
    if(s->top==-1) return true;
    else return false;
}

bool isFull(Stack* s){
    if(s->top==s->size-1) return true;
    else return false;
}

void push(Stack* s,int n){
    if(isFull(s)){
        cout<<"\n"<<"Not enough space";
        return;
    }
    s->top +=1;
    (s->arr)[s->top]=n;
}

void pop(Stack* s){
    if(isEmpty(s)){
        cout<<"\n"<<"Nothing to pop";
        return;
    }
    s->top -=1;
}

void display(Stack* s){
    if(isEmpty(s)){
        cout<<"\n"<<"Nothing in stack";
        return;
    }
    for(int i=0;i<=s->top;i++){
        cout<<"\n"<<(s->arr)[i];
    }
}

int main(){
    Stack s;
    s.size=15;
    s.top=-1;
    s.arr= (int*)malloc(s.size*sizeof(int));

    push(&s,1);
    push(&s,2);
    push(&s,3);
    push(&s,4);
    push(&s,5);
    push(&s,6);
    push(&s,7);
    push(&s,8);
    push(&s,9);
    push(&s,10);
    push(&s,11);
    push(&s,12);
    push(&s,13);
    push(&s,14);
    push(&s,15);
    push(&s,16);
    push(&s,17);
    push(&s,18);
    
    pop(&s);
    display(&s);
    return 0;
}