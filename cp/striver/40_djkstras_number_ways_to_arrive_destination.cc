/*
https://practice.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1
https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/
*/

// slow solution
class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        using vi = vector<int>;
        int mod = 1e9+7;
        vi cost(n, 1e9), freq(n, 0);
        vector<vi> gr[n];
        priority_queue<vi, vector<vi>, greater<vi> > pq;

        for(auto road: roads) {
            int u = road[0], v = road[1], t = road[2];
            gr[u].push_back({v, t});
            gr[v].push_back({u, t});
        }

        pq.push({0, 0}); // cost, city
        cost[0] = 0;
        freq[0] = 1;
        while(pq.size()) {
            auto node = pq.top(); pq.pop();
            int time = node[0], u = node[1];

            for(auto vt: gr[u]) {
                int v = vt[0], newTime = time+vt[1];
                if(cost[v] > newTime) {
                    cost[v] = newTime;
                    freq[v] = 1;
                    pq.push({newTime, v});
                } else if(cost[v] == newTime) {
                    freq[v] = (1LL+freq[v])%mod;
                    pq.push({newTime, v}); // makes slow
                }
            }
        }

        return freq[n-1];
    }
};


// fast solution
class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        using vi = vector<int>;
        int mod = 1e9+7;
        vi cost(n, 1e9), freq(n, 0);
        vector<vi> gr[n];
        priority_queue<vi, vector<vi>, greater<vi> > pq;

        for(auto road: roads) {
            int u = road[0], v = road[1], t = road[2];
            gr[u].push_back({v, t});
            gr[v].push_back({u, t});
        }

        pq.push({0, 0}); // cost, city
        cost[0] = 0;
        freq[0] = 1;
        while(pq.size()) {
            auto node = pq.top(); pq.pop();
            int time = node[0], u = node[1];

            for(auto vt: gr[u]) {
                int v = vt[0], newTime = time+vt[1];
                if(cost[v] > newTime) {
                    cost[v] = newTime;
                    freq[v] = 1;
                    pq.push({newTime, v});
                } else if(cost[v] == newTime) {
                    freq[v] = (1LL+freq[v])%mod;
                    pq.push({newTime, v}); // makes slow
                }
            }
        }

        return freq[n-1];
    }
};
