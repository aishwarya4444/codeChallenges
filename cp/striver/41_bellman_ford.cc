/*
https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

similar to djkstras but can handle negative weights also
both djkstras and bellman ford are "single source shortest path"
*/

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, 1e8);

        dist[S] = 0;
        // TC = O(VxE)
        // relax V-1 times
        for(int i=1; i<=V-1; i++) {
            for(auto edge: edges) {
                int u = edge[0], v = edge[1], wt = edge[2];
                if(dist[v] > dist[u]+wt) {
                    dist[v] = dist[u]+wt;
                }
            }
        }

        // if we do 1 more relaxation and if any change is possible
        // then negative cycle exists
        for(auto edge: edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            if(dist[v] > dist[u]+wt) {
                return {-1};
            }
        }

        return dist;
    }
};
