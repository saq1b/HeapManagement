#include <iostream>
#define n 10
using namespace std;
int heap[n];
int* malloc(unsigned int _size){
    static int cursor=0;
    // set first place = _size
    int *ptr = &(heap[cursor]);
//    cout<<"Address of heap[cursor] & ptr value "<<&heap[cursor]<<' '<<ptr;
    heap[cursor] = _size;
    ++cursor;  // start allocating from next location
    for(; cursor<_size; ++cursor){
        if(cursor==n-1){
//            cout<<"ptr="<<*ptr<<endl;
            *ptr=0;  // undo the allocation
            return NULL;  // Heap Full
        }
        heap[cursor] = 1;  // Let 1 represent allocated memory unit
    }
    cout<<_size<<" units of memory allocated at "<<ptr<<endl;
    return ptr;
}
void free(int *ptr){
//    cout<<ptr<<' '<<*ptr<<'#';
    if(ptr==NULL || *ptr==0 || *ptr==1){
        cout<<"Can't delete random memory locations\n";
        return;
    }
    const int _size=*ptr;
    for (int i=0; i<_size+1; ++i){
       *ptr = 0;
    }
    cout<<"Memory Freed Successfully\n";
}
int main(){
    for (int i=0; i<n; ++i){
        heap[i]=0;   // Free the heap
    }
    int *a=malloc(2);
//    cout<<"a, *a = "<<a<<','<<*a<<endl;
    if(a==NULL){
        cout<<"Memory Allocation Failed\n";
    }
    int *b=malloc(101);
    if(b==NULL){
        cout<<"Memory Allocation Failed\n";
    }
    free(a);
    free(b);
    return 0;
}
