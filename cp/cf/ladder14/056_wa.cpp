/*
https://codeforces.com/problemset/problem/508/C

https://codeforces.com/contest/508/submission/61954440
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int m, t, r, wi, candles=0;
    queue<int> q;

    cin>>m>>t>>r;

    for(int i=1; i<=m; i++) {
        cin>>wi;
        q.push(wi);
    }

    while(q.size()) {
        int start = q.front()-1;
        int end = start+t;
        if(start==end) {
            candles = -1;
            break;
        }
        candles += r;
        while(start<=end) {
            start++;
            if(q.size() && start>q.front()) {
                q.pop();
            }
        }
    }

    cout<<candles;

    return 0;

}
