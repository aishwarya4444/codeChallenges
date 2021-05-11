/*
https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/discuss/693984/c-binary-search-similar-to-painters-partition-problem-detailed-explanation
*/

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int start, mid, end, res=-1;
        int boquets, flowers;

        if(k*m > bloomDay.size()) {
            return res;
        }

        start = end = bloomDay[0];
        for(int day: bloomDay) {
            start = min(start, day);
            end = max(end, day);
        }

        while(start<=end) {
            mid = (end-start)/2+start;

            // find number of boquets
            boquets = 0;
            flowers = 0;
            for(int day: bloomDay) {
                if(day>mid) {
                    flowers = 0;
                    continue;
                }
                flowers++;
                if(flowers==k) {
                    flowers = 0;
                    boquets++;
                }
            }

            if(boquets>=m) {
                res = mid;
                end = mid-1;
            } else {
                start = mid+1;
            }
        }

        return res;

    }
};