#include <bits/stdc++.h>
using namespace std;

stack<pair<int, int>> clear_stack(stack<pair<int, int>> s){
    while(!s.empty())
        s.pop();
    return s;
}


vector<int> nearest_smallest_element_to_left(int a[], int l, stack<pair<int, int>> s){
    vector<int> nsl;
    for(int i=0; i<l; i++){
        while(!s.empty() && s.top().first > a[i])
            s.pop();
        if(s.empty())
            nsl.push_back(-1);
        else
            nsl.push_back(s.top().second);
        s.push({a[i],i});
    }
    return nsl;
}


vector<int> nearest_smallest_element_to_right(int a[],int l, stack<pair<int, int>> s){
    vector<int> nsr;
    for(int i=l-1; i>=0; i--){
        while(!s.empty() && s.top().first > a[i])
            s.pop();
        if(s.empty())
            nsr.push_back(l);
        else
            nsr.push_back(s.top().second);
        s.push({a[i],i});
    }
    reverse(nsr.begin(), nsr.end());
    return nsr;
}


vector<int> difference(vector<int> nsl, vector<int> nsr, int l){
    vector<int> diff;
    for(int i=0; i<l; i++){
        diff.push_back(nsr[i]-nsl[i]-1);
    }
    return diff;
}


int max_area_histogram(int a[], int l){
    stack<pair<int, int>> s;    
    vector<int> nsl = nearest_smallest_element_to_left(a,l,s);
    s = clear_stack(s);
    vector<int> nsr = nearest_smallest_element_to_right(a,l,s);
    vector<int> width = difference(nsl, nsr, l);
    vector<int> area;
    for(int i=0; i<l; i++){
        area.push_back(a[i]*width[i]);
    }
    return *max_element(area.begin(), area.end());
}

int main() {
    int a[]={6,2,5,4,5,1,6};
    int l=sizeof(a)/sizeof(a[0]);
    cout<<max_area_histogram(a,l);
    return 0;
}
