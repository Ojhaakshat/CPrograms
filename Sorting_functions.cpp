#include<bits/stdc++.h>
using namespace std;

bool compare1(int a, int b){
    return a<b;
}

bool compare2(int a, int b){
    return a>b;
}

void bubblesort(int ar[],int n){
    int counter=1;

    while(counter<n){

    for(int i=0;i<n-counter;i++){
        if(compare1(ar[i],ar[i+1])){
            swap(ar[i],ar[i+1]);
        }
    
    }
    counter++;
    }

}

void selectionsort(int ar[],int n){

    int start=0;

    while(start<n-1){

    for(int i=start+1;i<n;i++){
        if(compare2(ar[start],ar[i])){
            swap(ar[start],ar[i]);
        }
    }
    start++;
    }

}

void insertionsort(int ar[],int n){

    int devider=1;

    while(devider<n){
        for(int i=devider;i>0;i--){
            if(compare1(ar[i],ar[i-1])){
                swap(ar[i],ar[i-1]);
            }
            else{
                break;
            }

        }
        devider++;
    }

}

int main(){

    int arr[]={3,8,1,4,2,7};
    int n=sizeof(arr)/sizeof(arr[0]);

    // bubblesort(arr,n);
    // selectionsort(arr,n);
    insertionsort(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
