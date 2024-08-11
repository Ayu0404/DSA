/*

INCORRECT output generated

h1 - max area is 2
h2 - max area is 4
h3 - max area is 8
h4 - max area is 6

*/ 

#include <bits/stdc++.h>
using namespace std;

vector<int> nearest_smallest_left(vector<int> h){
    stack<pair<int, int>> s;
    vector<int> l;
    for(int i=0; i<h.size(); i++){
        while(!s.empty() && s.top().first >= h[i]){
            s.pop();
        }
        if(!s.empty() && s.top().first < h[i]){
            l.push_back(s.top().second);
        }
        if(s.empty()){
            l.push_back(-1);
        }
        s.push({h[i],i});
    }
    return l;
}


vector<int> nearest_smallest_right(vector<int> h){
    stack<pair<int, int>> s;
    vector<int> r;
    for(int i = h.size()-1; i>=0; i--){
        while(!s.empty() && s.top().first >= h[i]){
            s.pop();
        }
        if(!s.empty() && s.top().first < h[i]){
            r.push_back(s.top().second);
        }
        if(s.empty()){
            r.push_back(-1);
        }
        s.push({h[i],i});
    }
    reverse(r.begin(), r.end());
    return r;
}


vector<int> difference(vector<int> left, vector<int> right){
    vector<int> diff;
    for(int i=0; i<left.size(); i++)
        diff.push_back(right[i] - left[i] - 1);
    return diff;
}


vector<int> histogram_area(vector<int> h, vector<int> width){
    vector<int> area;
    for(int i=0; i<h.size(); i++)
        area.push_back(h[i]*width[i]);
    return area;
}


int max_area_histogram(vector<int> h){
    vector<int> left = nearest_smallest_left(h);
    vector<int> right = nearest_smallest_right(h);
    vector<int> width = difference(left, right);
    vector<int> area = histogram_area(h, width);
    return *max_element(area.begin(), area.end());
}

int max_histogram_binary_matrix(int a[4][4], int n, int m){
    int mx = INT_MIN;
    vector<int> v;

    for(int j=0; j<m; j++)
        v.push_back(a[0][j]);

    mx = max(mx, max_area_histogram(v));
    
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] == 0)
                v[j]=0;
            else
                v[j] = v[j] + a[i][j];
        }
        mx = max(mx, max_area_histogram(v));
    }

    return mx; 
}   

int main() {
    int a[4][4]={{0,1,1,0},{1,1,1,1},{1,1,1,1},{1,1,0,0}};
    int n=4, m=4;
    cout<<max_histogram_binary_matrix(a,n,m);
    return 0;
}
