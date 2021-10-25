/*
Mr. Stark decided to go for morning walk everyday for a healthy lifestyle.
He chose a community park which was near to his house.
The park has multiple entrances and resting places in it collectively called as junctions of the park.
All entrances and resting places are connected by walking tracks
such that it is possible to go from each junction to other either directly or by a path.
There are total N junctions in the park and N-1 walking tracks.
Mr. Stark decided to enter from one entrance and exit from the other and walk the longest distance.
Can you tell the longest distance Mr. Stark can walk in the park?

Input Format
First line of the input contains a single integer representing the number of junctions N in the park.
Next N-1 lines contains three integers A, B and C,
representing that junction A and junction B are connected by a bidirectional path of length C.

Constraints
0< N <=100000
1<= A,B <=N
1<= C <=100000

Output Format
Print a single integer representing the maximum distance Mr. Stark can walk .

Sample Input
5
1 2 1
2 5 10
2 3 2
3 4 3

Sample Output
15

Explanation
Entrances will be 1 and 3 .Path will be 1->2->3 .
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const int N = 100001;
int n;
ll ans = 0;
ll dp[N];
unordered_map<int, ll> g[N];

void dfs(int curr, int par) {

  priority_queue<ll, vector<ll>, greater<ll> > minHeap;

  for(auto entry: g[curr]) {
    int child = entry.first;
    ll cost = entry.second;
    if(child == par) continue;
    dfs(child, curr);
    minHeap.push(cost + dp[child]);
    if(minHeap.size() > 2) {
      minHeap.pop();
    }
  }

  ll max1 = 0, max2 = 0;

  if(minHeap.size()) {
    max1 = minHeap.top();
    minHeap.pop();
  }

  if(minHeap.size()) {
    max2 = minHeap.top();
    minHeap.pop();
  }

  dp[curr] = max(max1, max2);

  ans = max(ans, max1+max2);
}

int main(){
   cin>>n;

   for(int i=1; i<=n-1; i++){
       int a, b, c;
       cin>>a>>b>>c;
       g[a][b] = c;
       g[b][a] = c;
   }

   dfs(1, 0);

   cout<<ans;

}
