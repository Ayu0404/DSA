#include <bits/stdc++.h>
using namespace std;

void calc_hash(int n, int arr[]){
    map<char, int> hash_arr;

    for(int i=0; i<n; i++){
        hash_arr[arr[i]] +=1;
    }

    auto it = hash_arr.begin();
    while(it!=hash_arr.end()){
        cout<<"\n"<<it->first<<" "<<it->second;
        it++;
    } 
}

int main() {
    int arr[]={'a', 'b', 'f', 's', 'r', 'h', 'd', 'b', 'a', 'r', 'g'};
    int n= sizeof(arr)/sizeof(arr[0]);
    calc_hash(n, arr);
    return 0;
}