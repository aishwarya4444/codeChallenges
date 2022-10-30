/*
https://practice.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1
https://leetcode.com/problems/cheapest-flights-within-k-stops/

we do not use priority_queue which sorts based on price
because we have to consider stops here

it can happen that our intermediary stop is updated with small price
and because of it we are unable to reach destination because "K" stops are consumed before
*/

class Solution {
private:
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        using vi = vector<int>;
        queue<vi> q;
        vector<vi> gr[n];
        vector<int> cost(n, 1e9);

        for(auto flight: flights) {
            int u=flight[0], v=flight[1], price=flight[2];
            gr[u].push_back({v, price});
        }

        // TC = E = flights.size()

        q.push({-1, 0, src}); // stops, price, flight
        while(q.size()) {
            auto node = q.front(); q.pop();
            int stops = node[0], price = node[1], flight = node[2];
            if(stops == K) continue;

            for(auto route: gr[flight]) {
                int nextFlight = route[0], extraPrice = route[1];
                // we update cost for all flights
                // and its an excellent way to trim further high price routes
                if(cost[nextFlight] > price+extraPrice) {
                    cost[nextFlight] = price+extraPrice;
                    q.push({1+stops, price+extraPrice, nextFlight});
                }
            }
        }

        return cost[dst] == 1e9 ? -1 : cost[dst];
    }
};
