/*
https://leetcode.com/problems/magnetic-force-between-two-balls/

https://leetcode.com/problems/magnetic-force-between-two-balls/discuss/794245/problem-is-same-as-spoj-aggrcow-aggressive-cows-soln-and-link-included
*/

class Solution {
public:
    bool check(vector<int>& position, int limit, int m) {
        int pre = -position.back();
        int balls = 0;

        for(int dist: position) {
            if(dist-pre >= limit) {
                balls++;
                pre = dist;
            }
        }

        return balls >= m;
    }

    int maxDistance(vector<int>& position, int m) {
        int start, mid, end;
        int dist = -1;

        sort(position.begin(), position.end());

        start = 0;
        end = position.back()-position.front();

        while(start<=end) {
            mid = (end-start)/2+start;
            if(check(position, mid, m)) {
                dist = mid;
                start = mid+1;
            } else {
                end = mid-1;
            }
        }

        return dist;
    }
};
