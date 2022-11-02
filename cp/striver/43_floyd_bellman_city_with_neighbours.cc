/*
https://practice.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1
https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/
*/

// floyd warshall
// TC = V^3
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        for(auto edge: edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

        for(int i=0; i<n; i++) {
            dist[i][i] = 0;
        }

        for(int k=0; k<n; k++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    /*
                    // we can also put check for INF or 1e9 or INT_MAX
                    if(dist[i][k]==1e9 || dist[k][j]==1e9) continue;
                    */
                    if(dist[i][j] > dist[i][k]+dist[k][j]) {
                        dist[i][j] = dist[i][k]+dist[k][j];
                    }
                }
            }
        }

        int ans = -1, minCnt = n;
        for(int i=0; i<n; i++) {
            int cnt = 0;
            for(int j=0; j<n; j++) {
                if(dist[i][j] <= distanceThreshold) cnt++;
            }
            if(minCnt >= cnt) {
                minCnt = cnt;
                ans = i;
            }
        }

        return ans;
    }
};


// using djkstras
// TC = VE log V
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        using vi = vector<int>;
        vector<vi> gr[n];

        for(auto edge: edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            gr[u].push_back({v, w});
            gr[v].push_back({u, w});
        }

        int ans = -1, minCnt = n;
        for(int i=0; i<n; i++) {
            priority_queue<vi, vector<vi>, greater<vi> > pq;
            vi cost(n, 1e9);
            int cnt = 0;

            cost[i] = 0;
            pq.push({0, i}); // cost, vertex
            while(pq.size()) {
                auto cu = pq.top(); pq.pop();
                int c = cu[0], u = cu[1];

                for(auto vw: gr[u]) {
                    int v = vw[0], w = vw[1];
                    if(cost[v] > c+w) {
                        cost[v] = c+w;
                        pq.push({cost[v], v});
                    }
                }
            }

            for(int dist: cost) {
                if(dist <= distanceThreshold) {
                    cnt++;
                }
            }

            if(minCnt >= cnt) {
                minCnt = cnt;
                ans = i;
            }
        }
        return ans;
    }
};
