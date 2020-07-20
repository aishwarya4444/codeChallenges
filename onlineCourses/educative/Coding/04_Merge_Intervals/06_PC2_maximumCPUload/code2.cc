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

/*
class Solution {
private:
    struct compare {
        bool operator()(const vector<int> &t1, const vector<int> &t2) {
            return t1[2] > t2[2];
        }
    };
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<vector<int>, vector<vector<int>>, compare > pq;
        int pax, start, end;

        sort(trips.begin(), trips.end(), [](const vector<int> &t1, const vector<int> &t2) {
            return t1[1]<t2[1];
        });
        for(auto trip: trips) {
            pax = trip[0];
            start = trip[1];
            end = trip[2];
            while(pq.size() && start>=pq.top()[2]) {
                capacity += pq.top()[0];
                pq.pop();
            }
            capacity -= pax;
            if(capacity<0) {
                return false;
            }
            pq.push(trip);
        }
        return true;
    }
};
*/