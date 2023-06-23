//to stdy array as an ADT
#include<iostream>
#include<conio.h>
using namespace std;

struct myArray{
    int total_size, used_size;
    int* ptr;
};

void createArray(struct myArray* a, int tsize, int usize){
    a->total_size=tsize;
    a->used_size=usize;
    a->ptr = new int(tsize);
}

void show(struct myArray* a){
    for(int i=0;i<a->used_size;i++){
        cout<<*(a->ptr + i)<<" "<<&(a->ptr)[i]<<endl;
    }
}

void setVal(struct myArray* a)
{
    int n;
     for(int i=0;i<a->used_size;i++){
        cout<<"Enter value no. "<<i+1<<" : ";
        cin>>n;
        (a->ptr)[i]=n;
    }
}

void insert(struct myArray* a,int n,int p){
    if(a->used_size==a->total_size){
        cout<<"no enough space n array";
        return;
    }
    else if(p>a->used_size){
        cout<<"give position less than or equal to "<<a->used_size;
        return;
    }
    for(int i=a->used_size;i>0;i--){
        if(i==p+1){
            (a->ptr)[i]=(a->ptr)[p];
            (a->ptr)[p]=n;
            break;
        }
        (a->ptr)[i]=(a->ptr)[i-1];
    }
    a->used_size += 1;
}

void Delete(struct myArray* a,int p){
    if(a->used_size<=p){
        cout<<"no element in array at that posion"<<endl;
        return;
    }
    /*else if(p>a->used_size){
        cout<<"give position less than or equal to "<<a->used_size;
        return;
    }*/

    for(int i=p;i<a->used_size-1;i++){
        (a->ptr)[i]=(a->ptr)[i+1];
    }
    a->used_size -= 1;
}

int main(){
    struct myArray m;
    int n,p;
    createArray(&m,10,6);
    setVal(&m);
    show(&m);
    cout<<"Enter value : ";
    cin>>n;
    cout<<"Enter position (index) : ";
    cin>>p;
    insert(&m,n,p);
    cout<<"\n";
    show(&m);

    cout<<"Enter position to delete (index) : ";
    cin>>p;
    Delete(&m,p);
    show(&m);
    return 0;
}