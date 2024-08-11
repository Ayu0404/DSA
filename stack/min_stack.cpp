// with ans without a supporting stack

#include <bits/stdc++.h>
using namespace std;

stack<int> s;
stack<int> ss;

void push_elem(int a){
    s.push(a);
    if(ss.empty() || ss.top() >= a)
        ss.push(a);
}

void pop_elem(){
    int elem;
    if(!s.empty()){
        elem = s.top();
        s.pop();
    }
    if(elem == ss.top())
        ss.pop();
}

int min_elem(){
    if(s.empty())
        return -1;
    return ss.top();
}

int main() {
    // elements - {18,19,29,15,16};
    // push_elem(18);
    // push_elem(19);
    // push_elem(29);
    // push_elem(15);
    // pop_elem();
    // push_elem(15);
    // push_elem(16);
    cout<<min_elem();

    return 0;
}
