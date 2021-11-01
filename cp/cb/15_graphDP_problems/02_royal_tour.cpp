/*
In a Kingdom , there are N cities connected by M one-directional roads.
The King decided to construct statues of 20 different categories in all the cities
where one statue will be constructed in only one city.
After the construction, the king decided to go on a royal tour.
The happiness of king from the tour is determined by the maximum number of
statues of any kind that the king sees during his tour.
(Suppose on the selected path, the number of statues of three types are 6,3,8, then the king’s happiness will be 8.)
You are the king’s tour planner.
Select a proper path and tell the maximum happiness the king can get.
If the happiness is infinite ,print -1 (Check sample case for infinite happiness case) .

Input Format
First line of the input contains two integers representing
number of cities N present in the Kingdom and
number of paths between the cities M.
Second line contains N integers a1,a2,a3…..an representing the type of statue present in each country.
Next N-1 lines contains two integers A and B ,representing that there is a path that goes from city A to city B.

Constraints
0< N <=100000
0< M <=min((N*(N-1))/2,100000).
1<= ai <=20(Category of statue)

Output Format
Print a single integer representing the happiness of the King .Print -1 if the happiness is infinite .

Sample Input
5 4
1 2 1 3 1
1 2
1 3
3 4
4 5

Sample Output
3

Explanation
The following path 1->3->4->5 contain three cities having statues of category 1.
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const int N = 100001;
int n, m;
vector<int> gr[N];       // graph
int id[N];               // indegree
int c[N];
int ans = 0;
unordered_map<int, int> dp[N];

void topsort() {
  queue<int> q, order;

  for(int i=1; i<=n; i++) {
    if(id[i]==0) {
      int category = c[i];
      q.push(i);
      dp[i][category]++;
      ans = 1;
    }
  }

  while(q.size()) {
    int u = q.front();
    q.pop();

    order.push(u);

    // for leaf node update ans
    if(gr[u].size() == 0) {
      for(auto entry: dp[u]) {
        int category = entry.first;
        int count = entry.second;
        ans = max(ans, count);
      }
    }

    for(int v: gr[u]) {
      for(auto entry: dp[u]) {
        int category = entry.first;
        int count = entry.second;
        dp[v][category] = max(count, dp[v][category]);
      }
      id[v]--;
      if(id[v]==0) {
        q.push(v);
        int category = c[v];
        dp[v][category]++;
      }
    }
  }

  // graph has cycle
  // it is not DAG
  // infinite happiness is possible
  if(order.size() != n) {
    ans = -1;
  }
}

int main(){
  int u, v;

  cin>>n>>m;

  memset(id, 0, sizeof id);

  for(int i=1; i<=n; i++) {
    cin>>c[i];
  }

  for(int i=1; i<=m; i++) {
    cin>>u>>v;
    gr[u].push_back(v);
    id[v]++;
  }

  topsort();

  cout<<ans;

  return 0;
}
