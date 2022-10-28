/*
https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
*/

//Function to find the shortest distance of all the vertices
//from the source vertex S.
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // pairs in set are arranged in ascending order
    set<pair<int, int>> st;
    vector<int> dist(V, 1e9);

    dist[S] = 0;
    st.insert({0, S});

    while(st.size()) {
        auto it = *(st.begin());
        int d = it.first;
        int u = it.second;
        st.erase(it);

        for(auto vw: adj[u]) {
            int v = vw[0], w = vw[1];
            if(dist[v] > d+w) {
                // erase the longer distance for reaching v
                // so that we do not process it later
                if(dist[v] != 1e9) {
                    st.erase({dist[v], v});
                }

                dist[v] = d+w;
                st.insert({dist[v], v});
            }
        }
    }

    return dist;
}