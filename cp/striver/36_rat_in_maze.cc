/*
https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1

we use "queue" here and not "priority_queue"
reason is that we are stepping by 1 each time and distance increases by 1 each time we step
*/

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {

        if(source.first==destination.first && source.second==destination.second) {
            return 0;
        }

        using vi = vector<int>;
        vector<vi> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};
        queue<vi> q;
        int R=grid.size(), C=grid[0].size();
        vector<vi> dist(R, vi(C, 1e9));

        dist[source.first][source.second] = 0;
        q.push({0, source.first, source.second});
        while(q.size()) {
            auto node = q.front(); q.pop();
            int d = node[0], r = node[1], c = node[2];

            for(auto dir: dirs) {
                int row = r+dir[0], col = c+dir[1];
                if(row>=0 && row<R && col>=0 && col<C && grid[row][col]==1) {
                    if(dist[row][col] > d+1) {
                        dist[row][col] = d+1;
                        q.push({dist[row][col], row, col});
                    }
                }
            }
        }

        return dist[destination.first][destination.second] == 1e9 ? -1 : dist[destination.first][destination.second];
    }
};
