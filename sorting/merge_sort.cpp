#include <bits/stdc++.h>
using namespace std;

int merge(int arr[], int l, int m, int r){
    int n1=m-l+1;
    int n2=r-m;
    int left[n1],right[n2];
    int count=0;

    for(int i=0; i<n1; i++)
        left[i]=arr[l+i];
    for(int j=0; j<n2; j++)
        right[j]=arr[m+1+j];

    int i=0,j=0,k=l;
    
    // copying
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            arr[k]=left[i];
            i++;
        }else {
            arr[k]=right[j];
            count += n1-i;
            j++;
        }
        k++;
    }    

    // leftovers on left
    while(i<n1){
        arr[k]=left[i];
        i++;
        k++;
    }
    // leftovers on right
    while(j<n2){
        arr[k]=right[j];
        j++;
        k++;
    }
    return count;
}

int mergeSort(int arr[], int l, int r){
    int count=0;
    if(l>=r)
        return 0;
    int mid=l+(r-l)/2;
    count += mergeSort(arr,l,mid);
    count += mergeSort(arr,mid+1,r);
    count += merge(arr,l,mid,r);
    return count;
}

int main() {
    int N = 5;
    int arr[] = {2, 4, 1, 3, 5};
    cout<<mergeSort(arr,0,N-1)<<"\t";   
    return 0;
}