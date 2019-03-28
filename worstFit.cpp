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
    int maxDiff,diff,saveIndex=0;
    bool foundSpace;
    for (int i=0; i<n; ++i){  // serve request sequencially
        maxDiff=-1;
        foundSpace=false;
        cout<<"Requesting "<<request[i]<<endl;
        for(int j=0; j<n; ++j){
            diff=freeList[j] - request[i];
            if(diff>=0 && diff>maxDiff){
                foundSpace=true;
                maxDiff = diff;
                saveIndex=j;
            }
        }
        if(foundSpace){
            freeList[saveIndex]-=request[i];
            allocList[saveIndex]+=request[i];
            printArr(freeList,n);
            printArr(allocList,n);
        }
        else{
            cout<<"CAN'T ALLOCATE "<<request[i]<<endl;
        }
    }
    return 0;
}
