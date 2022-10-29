/*

V nodes
E edges ~ approx V^2 for densely connected graph

TC -- we loop roughly over all nodes and in each loop we pop & iterate over edges & push
= nodes * (log heap_size + (nodes-1) * log heap_size)
= V * (V * log heap_size)
= V^2 * (log heap_size)
= E (log heap_size) -- heap size can be equal to number of nodes because we erase / do not process same node
= E log V

*/

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // pairs in set are arranged in ascending order
        set<pair<int, int>> st;
        vector<int> dist(V, 1e9);

        dist[S] = 0;
        st.insert({0, S});

        while(st.size()) { // loop over all nodes
            auto it = st.begin(); // look at top - O(1)
            int d = it->first;
            int u = it->second;
            st.erase(it); // pop or erase - O(log nodes)

            for(auto vw: adj[u]) { // loop over all neighbouring nodes
                int v = vw[0], w = vw[1];
                if(dist[v] > d+w) {
                    // erase the longer distance for reaching v
                    // so that we do not process it later
                    if(dist[v] != 1e9) {
                        st.erase({dist[v], v}); // erase - O(log nodes)
                    }

                    dist[v] = d+w;
                    st.insert({dist[v], v}); // push or insert - O(log nodes)
                }
            }
        }

        return dist;
    }
};