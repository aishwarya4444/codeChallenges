/*
Racing Star Rick was bored of racing on small tracks in his city.
He suggested the Royal Racers to organize their next race championship in Pingpong City.
Pingpong is the largest city present in the Kingdom which have longer roads as compared to other cities.
There are N junctions in Pingpong City.
These junctions are connected by M directed roads of varying lengths.
There are no loops in the city to prevent confusion among residents.
The organizers decided to choose longest path in the city for the upcoming racing event.
Due to the Humongous size of the city, they were not able to find the required path.
Can you help them in finding the maximum length path?

Input Format
First line of the input contains two integers representing the number of junctions N in Pingpong city
and number of paths M between the junctions.
Next M lines contains two integers A and B,
representing that junction A and junction B are connected by a directed path.

Constraints
0< N <=100000
0< M <min((N*(N-1))/2,100000)
1<= A,B <=N

Output Format
Print a single integer representing the maximum distance path that can be chosen .

Sample Input
4 5
1 2
3 2
1 3
2 4
3 4

Sample Output
3

Explanation
The longest path will be 1->3->2->4 .
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const int N = 100001;
int n, m;
vector<int> gr[N];       // graph
int id[N];               // indegree
int dp[N];

int dfs(int u) {

  if(dp[u] != -1) {
    return dp[u];
  }

  int res = 0;
  for(int v: gr[u]) {
    res = max(res, 1+dfs(v));
  }

  return dp[u] = res;
}

int main(){
  int u, v;

  cin>>n>>m;

  memset(id, 0, sizeof id);

  for(int i=1; i<=m; i++) {
    cin>>u>>v;
    gr[u].push_back(v);
    id[v]++;
  }

  memset(dp, -1, sizeof dp);

  int ans = 0;
  for(int i=1; i<=n; i++) {
    if(id[i]==0) {
      ans = max(ans, dfs(i));
    }
  }

  cout<<ans;

  return 0;
}
