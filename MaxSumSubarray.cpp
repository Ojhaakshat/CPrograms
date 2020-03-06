#include<bits/stdc++.h>
using namespace std;

int maxsumsubsubarrayO3(int ar[],int n){

    int sum,maxsum=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            sum=0;
            for(int k=i;k<=j;k++){
                sum+=ar[k];
            }
        maxsum=max(maxsum,sum);

        }
    }
    return maxsum;

}
int maxsumsubsubarrayO2(int ar[],int n){

    int maxsum=INT_MIN,sum;
    for(int i=0;i<n;i++){
        sum=0;
        for(int j=i;j<n;j++){
            sum+=ar[j];
            maxsum=max(maxsum,sum);
        }
    }
    return maxsum;
}
int maxsumsubsubarrayO1(int ar[],int n){
    int maxsum=INT_MIN;
    int carryforward,sum=0;
    for(int i=0;i<n;i++){
        sum+=ar[i];
        carryforward=max(sum,ar[i]);
        maxsum=max(maxsum,carryforward);
    }
    return maxsum;
}

int main(){

    int arr[]={1,2,-2,4,-6,7};
    int n=sizeof(arr)/sizeof(arr[0]);

    int sum3=maxsumsubsubarrayO3(arr,n);
    int sum2=maxsumsubsubarrayO2(arr,n);
    int sum1=maxsumsubsubarrayO1(arr,n);

    cout<<sum3<<" "<<sum2<<" "<<sum1<<endl;

    return 0;
}
