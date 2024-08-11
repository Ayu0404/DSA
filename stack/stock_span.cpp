// a variation in Nearest greatest left element

// problem statement - find numbers that number of numbers that are less than the current number, including the current number

#include <bits/stdc++.h>
using namespace std;

void print(vector<int> a){
    for(auto i:a) cout<<i<<" ";
}

void stock_span(int a[], int s){
    vector<int> ans;
    stack<pair<int, int>> st; // first is element and second is it's index

    for(int i=0; i<s; i++){
        if(st.empty()){
            ans.push_back(-1);
        }
        if(st.size()>0 && st.top().first>a[i]){
            ans.push_back(st.top().second);
        }
        if(st.size()>0 && st.top().first<a[i]){
            while(st.size()>0 && st.top().first<a[i]){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(-1);
            }
            if(st.size()>0 && st.top().first>a[i]){
                ans.push_back(st.top().second);
            }    
        }
        st.push({a[i],i});
    }

    for(int i=0; i<ans.size(); i++){
        ans[i]=i-ans[i];
    }

    print(ans);
}
int main() {
    int a[]={100,80,60,70,60,75,85};
    int s=sizeof(a)/sizeof(a[0]);
    stock_span(a,s);
    return 0;
}