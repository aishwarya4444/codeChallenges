// 30/30 cases passed
// 100/100 marks
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<climits>
#include<utility>

using namespace std;

unordered_map<int, vector<pair<int, int> > > graph;
unordered_map<int, bool> visited;

void dfs(int src, int &des, int &minTime, int tim) {
    if(src==des) {
        minTime = min(tim, minTime);
        return;
    }

    if(visited[src]) {
        return;
    }

    visited[src] = true;
    for(auto node: graph[src]) {
        dfs(node.first, des, minTime, tim+node.second);
    }
    visited[src] = false;
}

int main() {

    int n, node, N, src, des, tim, minTime=INT_MAX;

    cin>>N;
    for(n=0; n<N; n++) {
        cin>>node;
        visited[node] = false;
        graph[node] = vector<pair<int, int> >();
    }

    cin>>N;
    for(n=0; n<N; n++) {
        cin>>src>>des>>tim;
        graph[src].push_back(make_pair(des, tim));
    }

    cin>>src>>des;

    if(src==des) {
        cout<<"0\n";
        return 0;
    }

    visited[src] = true;
    for(auto node: graph[src]) {
        tim = node.second;
        dfs(node.first, des, minTime, tim);
    }

    if(minTime==INT_MAX) {
        minTime = -1;
    }
    cout<<minTime;
    return 0;
}

/*
4
2
5
7
9
4
2 9 2
7 2 3
7 9 7
9 5 1
7
9
*/
