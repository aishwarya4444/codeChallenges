/*
https://practice.geeksforgeeks.org/problems/path-with-minimum-effort/1
https://leetcode.com/problems/path-with-minimum-effort/
*/

class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        using vi = vector<int>;
        priority_queue<vi, vector<vi>, greater<vi>> pq;
        int R = heights.size(), C = heights[0].size();
        vector<vi> effort(R, vi(C, 1e9));
        vector<vi> dirs = {{0,-1}, {0,1}, {1,0}, {-1,0}};

        effort[0][0] = 0;
        pq.push({0, 0, 0});
        while(pq.size()) {
            auto node = pq.top(); pq.pop();
            int e = node[0], r = node[1], c = node[2];

            if(r==R-1 && c==C-1) return e;
            for(auto dir: dirs) {
                int row = r+dir[0], col = c+dir[1];
                if(row>=0 && row<R && col>=0 && col<C) {
                    int newEffort = max(e, abs(heights[r][c] - heights[row][col]));
                    if(effort[row][col] > newEffort) {
                        effort[row][col] = newEffort;
                        pq.push({newEffort, row, col});
                    }
                }
            }
        }

        return -1; // not reachable
    }
};
