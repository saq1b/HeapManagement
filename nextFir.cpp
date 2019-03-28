#include <iostream>
const int n=10;
using namespace std;
inline void printArr(int a[], int n){
    for (int i=0; i<n; ++i)
        cout<<a[i]<<'\t';
    cout<<endl;
}
int main(int argc, char* argv[]){
    int freeList[n]={10,30,50,80,100,200,300,500,700,1000};
    int allocList[n]={0,0,0,0,0,0,0,0,0,0};
    int request[n]={91,45,223,445,9,7,2,60,759,991};
    // Best Fit
    int saveIndex=0;
    bool foundSpace;
    for (int i=0; i<n; ++i){
        foundSpace=false;
        cout<<"Requesting "<<request[i]<<endl;
        for(int j=saveIndex; j<n; ++j){  // Change
            if(freeList[j]>=request[i]){
                foundSpace=true;
                saveIndex=j;
                break;
            }
        }
        if(foundSpace){
            freeList[saveIndex]-=request[i];
            allocList[saveIndex]+=request[i];
            cout<<"Free_List\t";
            printArr(freeList,n);
            cout<<"Alloc_List\t";
            printArr(allocList,n);
        }
        else{
            cout<<"COULDN'T ALLOCATE "<<request[i]<<endl;
        }
    }
    return 0;
}

