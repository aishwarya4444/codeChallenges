/*
https://practice.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1
*/

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        using vi = vector<int>;
        queue<vi> q;
        vector<bool> visited(1e5+1, false);
        set<int> nums;

        for(int num: arr) {
            nums.insert(num);
        }

        // TC = O(10^5 * nums.size())
        visited[start] = true;
        q.push({0, start}); // steps, product
        while(q.size()) {
            auto node = q.front(); q.pop();
            int steps = node[0], product = node[1];

            for(int num: nums) {
                int newProduct = (1LL*product*num)%100000;
                if(visited[newProduct]) continue;
                visited[newProduct] = true;
                if(newProduct == end) return 1+steps;
                else q.push({1+steps, newProduct});
            }
        }

        return -1;
    }
};
