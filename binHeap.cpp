#include<iostream>
#include<conio.h>
using namespace std;

struct Heap{
    int *arr;
    int count, capacity, heapType;
};

struct Heap* createHeap(int capacity, int heapT){
    struct Heap* h = new Heap();

    h->heapType = heapT;
    h->count= 0;
    h->capacity = capacity;
    h->arr = new int(capacity);
    return h;
}

int parent(struct Heap* h, int i){
    if(i<=0 || i>=h->count){
        return -1;
    }
    return (i-1)/2;
}

int leftChild(struct Heap* h, int i){
    int l=2*i+1;
    if(l>=h->count){
        return -1;
    }
    return l;
}

int rightChild(struct Heap* h, int i){
    int r=2*i+2;
    if(r>=h->count){
        return -1;
    }
    return r;
}

// heapify the element at location i
void percolateDown(struct Heap* h, int i){
    int l, r, max, temp;
    l= leftChild(h,i);
    r= rightChild(h, i);

    if(l!=-1 && h->arr[l]> h->arr[i]){
        max=l;
    }
    else 
        max=i;

    if(r!=-1 && h->arr[r]> h->arr[max])
        max=r;

    if(max != i){
        temp = h->arr[i];
        h->arr[i] = h->arr[max];
        h->arr[max] = temp;
        percolateDown(h,max);
    }
}

// heapify array
void buildHeap(struct Heap* h, int A[], int n){
    if(h== NULL){
        return;
    }
    for(int i=0;i<h->count;i++){
        int l= leftChild(h,i);
        int r= rightChild(h, i);
        if(l!=-1 && h->arr[l]> h->arr[i]){
            int temp = h->arr[l];
            h->arr[l]= h->arr[i];
            h->arr[i] = temp;
        }
        if(r!=-1 && h->arr[r]> h->arr[i]){
            int temp = h->arr[r];
            h->arr[r]= h->arr[i];
            h->arr[i] = temp;
        }
        if(l!=-1 && h->arr[l]> h->arr[i]){
            int temp = h->arr[l];
            h->arr[l]= h->arr[i];
            h->arr[i] = temp;
        }
    }
}
