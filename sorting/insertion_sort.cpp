#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        for(int j=0; j<n; j++){
                if(arr[i]<arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
    cout<<"\nSorted Arr";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}

int main() {
    int N = 5;
    int arr[] = {4, 1, 3, 9, 7};
    insertionSort(arr,N);
    return 0;
}