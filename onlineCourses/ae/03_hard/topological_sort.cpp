#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> topologicalSort(vector<int> jobs, vector<vector<int>> deps) {
  // Write your code here.
	int par, child, J=jobs.size();
	unordered_map<int, vector<int> > graph;
	unordered_map<int, int> indegree;
	vector<int> result;
	queue<int> src;

	// init graph and indegree
	for(auto job: jobs) {
		graph[job] = vector<int>();
		indegree[job] = 0;
	}

	// populate graph and indegree
	for(auto dep: deps) {
		par = dep[0];
		child = dep[1];
		graph[par].push_back(child);
		indegree[child]++;
	}

	// find sources
	for(auto entry: indegree) {
		if(entry.second == 0) {
			src.push(entry.first);
		}
	}

	// find sequence
	while(src.size()) {
		par = src.front();
		src.pop();
		result.push_back(par);

		for(int child: graph[par]) {
			indegree[child]--;
			if(indegree[child] == 0) {
				src.push(child);
			}
		}
	}
  return result.size()==J ? result : vector<int>();
}
