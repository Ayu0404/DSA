#include <bits/stdc++.h>
using namespace std;

int get_bin(int n){
    long long int num=0,rem;
    while(n>0){
        rem=n%2;
        num = num*10 + rem;
        n=n/2;
    }
    return num;
}

int getMax(int x) {
    long long int bin_num=get_bin(x);
    string s = to_string(bin_num);
    int i=0;
    reverse(s.begin(),s.end());
    cout<<bin_num<<' ';

    while(i<s.length()){
        if(s[i]!='1'){
            s[i]='1';
        }
        i +=2;
    }

    int ans=0;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='1'){
            ans += pow(2,i);
        }
    }
    return ans;
}

int main() {
    int x=82;
    // cout<<getMax(x)<<' ';
    getMax(x);
    return 0;
}
