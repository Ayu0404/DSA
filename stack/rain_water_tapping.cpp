#include <bits/stdc++.h>
using namespace std;

int rain_water_area(int a[], int size){
    int sum=0;
    int left[size], right[size], area[size];

    // initialize 0th value and then compare to find the max value further.  Between - left[i] with a[i]
    left[0]=a[0];
    for(int i=1; i<size; i++){
        left[i]=max(left[i-1],a[i]);
    }

    // initialize (size-1)th value and then compare to find the max value further.  Between - right[i] with a[i]
    right[size-1]=a[size-1];
    for(int i=size-2; i>=0; i--){
        right[i]=max(right[i+1],a[i]);
    }

    // area for each height
    for(int i=0; i<size; i++){
        area[i]=min(left[i],right[i])-a[i];
    }

    // sum of area
    for(int i=0; i<size-1; i++){
        sum += area[i];
    }

    return sum;
}

int main() {
    int a[]={3,0,0,2,0,4};
    int size=sizeof(a)/sizeof(a[0]);
    cout<<rain_water_area(a,size);
    return 0;
}