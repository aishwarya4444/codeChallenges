// 30/30 cases passed
// 100/100 marks
#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>

using namespace std;

int main() {
    unordered_map<int, vector<int> > graph;
    unordered_map<int, bool> visited;
    queue<int> q;

    int n, node, N, src, dest;

    cin>>N;
    for(n=0; n<N; n++) {
        cin>>node;
        graph[node] = vector<int>();
        visited[node] = false;
    }

    cin>>N;
    for(n=0; n<N; n++) {
        cin>>src>>dest;
        graph[src].push_back(dest);
    }

    cin>>src>>dest;
    if(src==dest) {
        cout<<"1\n";
        return 0;
    }

    q.push(src);

    while(q.size()) {
        N = q.size();
        while(N--) {
            n = q.front();
            q.pop();
            visited[n] = true;
            for(auto node: graph[n]) {
                if(visited[node]) {
                    continue;
                }
                if(node == dest) {
                    cout<<"1\n";
                    return 0;
                }
                q.push(node);
            }
        }
    }


    cout<<"0\n";
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
