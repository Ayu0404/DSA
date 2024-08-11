#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};

int knapsack(int N, int W, Item arr[]){
    int sub_set[];
    for(int i=0; i<N; i++){
        if(arr[i].weight<W)
            sub_set.push()
    }
}

int main() {
    int N=3, W=4;
    Item arr[] = {{1, 4}, {2, 5}, {3, 1}};
    knapsack(N, W, arr);

    return 0;
}