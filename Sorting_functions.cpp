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
//QUICKSORT
int partition(int ar[],int start,int end){
    int pivot=ar[start+(end-start)/2];
    while(start<=end){
        while(ar[start]<=pivot){
            start++;
        }
        while(ar[end]>=pivot){
            end--;
        }
        if(start<=end){
            swap(ar[start],ar[end]);
        }
    }
    return start;
}
void quicksort(int ar[],int start,int end){
    if(start>=end){
        return;
    }
    int index=partition(ar,start,end);

    quicksort(ar,start,index-1);
    quicksort(ar,index+1,end);
}

//MERGE SORT
void merge(int arr[],int start,int end){
	
	int n = end-start+1;
	int temp[n];

	int mid = start + (end - start)/2;

	int i = start;
	int j = mid+1;

	int k = 0;

	while(i<=mid and j<=end){

		if(arr[i]<=arr[j]){
			temp[k] = arr[i];
			i++;
			k++;
		}else{
			temp[k] = arr[j];
			k++;
			j++;
		}
	}

	while(i<=mid){
		temp[k] = arr[i];
		i++;
		k++;
	}

	while(j<=end){
		temp[k] = arr[j];
		j++;
		k++;
	}

	int pos = 0;
	for(int x=start;x<=end;x++){
		arr[x] = temp[pos];
		pos++;
	}
}

void mergeSort(int arr[],int start,int end){
	if(start==end){
		return;
	}

	int mid = start + (end - start)/2;

	mergeSort(arr,start,mid);
	mergeSort(arr,mid+1,end);

	merge(arr,start,end);	
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

