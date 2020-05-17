class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> m;
        queue<int> q;
        priority_queue<int> maxHeap;
        int time, freq, res=0;

        for(auto task: tasks) {
            m[task]++;
        }

        for(auto entry: m) {
            maxHeap.push(entry.second);
        }

        while(maxHeap.size()) {
            for(time=0; time<=n && maxHeap.size(); time++) {
                freq = maxHeap.top();
                maxHeap.pop();
                if(freq>1) {
                    q.push(freq-1);
                }
            }

            if(q.size()) {
                res = res+n+1;
                while(q.size()) {
                    maxHeap.push(q.front());
                    q.pop();
                }
            } else {
                res = res+time;
            }
        }

        return res;
    }
};
