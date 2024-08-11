// study and implement again

#include <bits/stdc++.h>
using namespace std;

int min_val = INT_MAX;
stack<int> s;

void push_elem(int a){
    if(s.empty() ){
        min_val=a;
        s.push(a);
    }
    if(a > min_val){
        s.push(a);
    }
    if(a < min_val){
        s.push(2*a-min_val);
        min_val=a;
    }
}

int pop_elem(){
    if(s.empty())
        return -1;
    if(s.top()<min_val){ // flag?
        min_val=2*min_val-s.top(); // to find previous value in stack and then pop the flag
    }
    s.pop();
}

int top_elem(){
    if(s.empty())
        return -1;
    if(s.top()<min_val)
        return min_val;
    else 
        return s.top();
}

int main() {
    // elements - {18,19,29,15,16};

    return 0;
}