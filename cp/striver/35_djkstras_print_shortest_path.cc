/*
https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
*/

// soln 1 - make graph using map
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        using pii = pair<int, int>;
        // make graph
        map<int, vector<pii>> adj;
        for(auto edge: edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> dist(n+1, 1e9), par(n+1);

        for(int u=1; u<=n; u++) {
            par[u] = u;
        }

        dist[1] = 0;
        pq.push({0, 1});
        while(pq.size()) {
            auto du = pq.top();
            pq.pop();
            int d = du.first;
            int u = du.second;

            for(auto vw: adj[u]) {
                int v = vw.first, w = vw.second;
                if(dist[v] > d+w) {
                    par[v] = u;
                    dist[v] = d+w;
                    pq.push({dist[v], v});
                }
            }
        }

        vector<int> res;

        if(dist[n] == 1e9) {
            res.push_back(-1);
        } else {
            while(n!=1) {
                res.push_back(n);
                n = par[n];
            }
            res.push_back(n);
            reverse(res.begin(), res.end());
        }

        return res;
    }
};


// soln 2 - make graph using vector
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        using pii = pair<int, int>;
        // make graph
        vector<pii> adj[n+1];
        for(auto edge: edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> dist(n+1, 1e9), par(n+1);

        for(int u=1; u<=n; u++) {
            par[u] = u;
        }

        dist[1] = 0;
        pq.push({0, 1});
        while(pq.size()) {
            auto du = pq.top();
            pq.pop();
            int d = du.first;
            int u = du.second;

            for(auto vw: adj[u]) {
                int v = vw.first, w = vw.second;
                if(dist[v] > d+w) {
                    par[v] = u;
                    dist[v] = d+w;
                    pq.push({dist[v], v});
                }
            }
        }

        vector<int> res;

        if(dist[n] == 1e9) {
            res.push_back(-1);
        } else {
            while(n!=1) {
                res.push_back(n);
                n = par[n];
            }
            res.push_back(n);
            reverse(res.begin(), res.end());
        }

        return res;
    }
};
