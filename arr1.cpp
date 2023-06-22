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
int main(){
    struct myArray m;
    createArray(&m,10,2);
    setVal(&m);
    show(&m);
    return 0;
}