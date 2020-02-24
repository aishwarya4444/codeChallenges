// 25/30 cases passed
// 85/100 marks
#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>

using namespace std;

unordered_map<int, vector<int> > graph;
unordered_map<int, bool> visited;
set<int> del;

void dfs(int src, int &des) {
    if(visited[src]) {
        return;
    }
    visited[src] = true;
    for(auto node: graph[src]) {
        if(node == des) {
            del.insert(src);
            continue;
        }
        dfs(node, des);
    }
    visited[src] = false;
}

int main() {

    int n, N, node, src, des;

    cin>>N;
    for(n=0; n<N; n++) {
        cin>>node;
        graph[node] = vector<int>();
        visited[node] = false;
    }

    cin>>N;
    for(n=0; n<N; n++) {
        cin>>src>>des;
        graph[src].push_back(des);
    }

    cin>>src>>des;
    if(src==des) {
        cout<<src;
        return 0;
    }

    visited[src] = true;
    for(auto node: graph[src]) {
        if(node == des) {
            del.insert(src);
            continue;
        }
        dfs(node, des);
    }

    if(del.size()) {
        for(auto node: del) {
            cout<<node<<' ';
        }
    } else {
        cout<<-1;
    }
    return 0;
}

/*
4
2
5
7
9
4
2 9
7 2
7 9
9 5
7
9
*/
