#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n){
    for(int i=0; i<n; i++){
        int min_val=arr[i];
        int idx=i;
        for(int j=i; j<n; j++){
            if(min_val>arr[j]){
                min_val=arr[j];
                idx=j;
            }
        }
        
        if(arr[i]>min_val){
            int temp = arr[i];
            arr[i]=min_val;
            arr[idx]=temp;
        }

    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main() {
    int N = 5;
    int arr[] = {4, 1, 3, 9, 7};
    bubbleSort(arr,N);
    return 0;
}