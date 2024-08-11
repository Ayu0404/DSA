#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};

 double fractionalKnapsack(int w, Item arr[], int n) {
    double kp_v=0;
    int kp_w=0;

    for(int i=0; i<n; i++){
        if(arr[i].weight < w){
            if(arr[i].weight < w - kp_w){
                kp_v += arr[i].value;
                kp_w += arr[i].weight;
            } else if((w - kp_w)>0){
                kp_v += (arr[i].value/ arr[i].weight)*(w - kp_w);
                kp_w += w - kp_w;
            }
        }
    }

    cout<<"\nkp_v "<<kp_v<<"\n";
    return kp_v;
    }

int main() {
    int n=3;
    int w=50;
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    Item arr2[] = {{60,10},{100,20}};
    // fractionalKnapsack(w, arr, n);
    fractionalKnapsack(50, arr2, 2);

    return 0;
}
