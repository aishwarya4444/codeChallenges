/*
https://codeforces.com/problemset/problem/501/C

Note that every non-empty forest has a leaf(vertex of degree 1).
Let's remove edges one by one and maintain actual values (degreev,sv) as long as graph is not empty.
To do so, we can maintain the queue(or stack) of the leaves.
On every iteration we dequeue vertex v and remove edge (v,sv) and update values for vertex sv: degreesv -= 1 and ssv ^= v.
If degree of vertex sv becomes equal to 1, we enqueue it.

When dequeued vertex has zero degree, just ignore it because we have already removed all edges of corresponding tree.

*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n, di, si;
    vector<pair<int, int> > res;
    queue<int> q;

    cin>>n;

    int degree[n];
    int sum[n];

    for(int i=0; i<n; i++) {
        cin>>degree[i]>>sum[i];
        if(degree[i]==1) {
            q.push(i);
        }
    }

    while(q.size()) {
        int u = q.front();
        q.pop();
        if(degree[u]==0) {
            continue;
        }
        int v = sum[u];
        degree[u]--;
        degree[v]--;
        sum[v] ^= u;
        if(degree[v]==1) {
            q.push(v);
        }
        res.push_back({u, v});
    }

    cout<<res.size();
    for(auto uv: res) {
        cout<<endl<<uv.first<<' '<<uv.second;
    }

    return 0;

}
