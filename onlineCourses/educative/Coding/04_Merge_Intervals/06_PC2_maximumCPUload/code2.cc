// https://leetcode.com/problems/car-pooling/
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> m;
        int start, end, pax, sum=0;
        
        for(auto trip: trips) {
            pax = trip[0];
            start = trip[1];
            end = trip[2];
            m[start]+=pax;
            m[end]-=pax;
        }
        
        for(auto entry: m) {
            sum += entry.second;
            if(sum>capacity) {
                return false;
            }
        }
        
        return true;
    }
};