/*
https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
*/

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // min heap
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> >> pq;
    vector<int> dist(V, 1e9);

    dist[S] = 0;
    pq.push({0, S});

    while(pq.size()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        for(auto vw: adj[u]) {
            int v = vw[0], w = vw[1];
            if(dist[v] > d+w) {
                dist[v] = d+w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}