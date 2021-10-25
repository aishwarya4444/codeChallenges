/*
During a fierce storm ,the great sailor Popeye got shipwrecked.
He ,being the only survivor from the crew got marooned on a strange uninhabited island.
In search of food ,he found a magic tree with N nodes in it.
The tree was protected by a golden fairy.
On each node ,there is an integer written on it.
The fairy promised Popeye that if he is able to select exactly two non intersecting subtrees of this tree,
then she will give Popeye gold coins equal to the sum of values on all nodes of both the subtrees.

Popeye being poor in mathematics asks you to find the maximum coins he can get (if any).
Popeye cannot select only one subtree .He must select two subtrees or none at all .

(Two subtrees are non intersecting if they do not have any node in common.)

Note:
The nodes can have negative values .If total sum is negative , Popeye will not get any coins .

Input Format
First line of the input contains single integer representing the number of nodes N in the tree.
Second line contains N integers a1,a2,a3…..an representing the value on each node.
Next N-1 lines contains two integers A and B, representing that node A and node B are connected .

Constraints
0<N<=100000
-100000 <= ai <= 100000 (Value on node)

Output Format
Print a single integer representing the maximum coins Popeye can get .

Sample Input
5
-20 -1 8 1 7
1 2
1 4
2 3
2 5

Sample Output
15

Explanation
The best choice is to choose subtrees having node 3 and node 4 only.


https://ide.codingblocks.com/s/254103?_ga=2.74688914.1423797722.1634990299-924970859.1606752496
*/

#include<bits/stdc++.h>
using namespace std;

const int N=100001;

int a[N];
int ans=0;

vector<int>subtree_sum(N),max_subtree(N);
vector<int> graph[N];

void dfs(int curr, int par){
    int maxSum = INT_MIN;
    priority_queue<int, vector<int>, greater<int> > minHeap;

    subtree_sum[curr] = a[curr];

    for(auto child: graph[curr]){
        if(child == par) continue;

        dfs(child, curr);

        subtree_sum[curr] += subtree_sum[child];
        maxSum = max(maxSum, subtree_sum[child]);

        minHeap.push(max_subtree[child]);
        if(minHeap.size() > 2) {
            minHeap.pop();
        }
    }

    if(minHeap.size() == 2) {
        int total=0;

        total += minHeap.top(); minHeap.pop();
        total += minHeap.top(); minHeap.pop();

        ans = max(ans, total);
    }

    max_subtree[curr] = max(maxSum, subtree_sum[curr]);
}

int main(){
    int n;

    cin>>n;
    for(int i=1; i<=n; i++) {
        cin>>a[i];
    }

    for(int i=1; i<=n-1; i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1,0);

    cout<<ans;

    return 0;

}
