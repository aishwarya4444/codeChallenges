#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<queue>
#include<algorithm>

#define ULI unsigned long int
using namespace std;


unordered_map<int, vector<int> > graph;
vector<char> power;
vector<char> allPowers;
vector<bool> visited;
bool found;
int N, Q;

void dfs(int u, int v) {
  if(visited[u] || found) {
    return;
  }

  if(u==v) {
    unordered_map<char, int> m;
    int count=0;
    vector<char> freq;
    allPowers.push_back(power[u]);
    for(auto p: allPowers) {
      m[p]++;
      count = max(count, m[p]);
    }
    for(auto entry: m) {
      if(entry.second == count) {
        freq.push_back(entry.first);
      }
    }
    sort(freq.begin(), freq.end());
    cout<<freq[0]<<endl;
    found = true;
	  freq.clear();
    m.clear();
    return;
  }

  visited[u] = true;
  allPowers.push_back(power[u]);

  for(auto node: graph[u]) {
    if(visited[node]) {
      continue;
    }
    dfs(node, v);
  }

  allPowers.pop_back();
  visited[u] = false;
}

int main() {
	int i, u, v;
	char p;

	cin>>N;
	power = vector<char>(N+1, '.');
	visited = vector<bool>(N+1, false);

	for(i=1; i<=N; i++) {
	  cin>>p;
	  power[i] = p;
	}

	for(i=1; i<=N-1; i++) {
	  cin>>u>>v;
	  graph[u].push_back(v);
	  graph[v].push_back(u);
	}

	cin>>Q;
	while(Q--) {
	  cin>>u>>v;

	  found = false;
	  allPowers.clear();

	  dfs(u, v);
	}

	return 0;
}
