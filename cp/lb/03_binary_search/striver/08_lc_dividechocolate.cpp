/*
https://leetcode.com/problems/divide-chocolate/

You have one chocolate bar that consists of some chunks. Each chunk has its own sweetness given by the array sweetness.

You want to share the chocolate with your k friends so you start cutting the chocolate bar into k + 1 pieces using k cuts, each piece consists of some consecutive chunks.

Being generous, you will eat the piece with the minimum total sweetness and give the other pieces to your friends.

Find the maximum total sweetness of the piece you can get by cutting the chocolate bar optimally.



Example 1:

Input: sweetness = [1,2,3,4,5,6,7,8,9], k = 5
Output: 6
Explanation: You can divide the chocolate to [1,2,3], [4,5], [6], [7], [8], [9]
Example 2:

Input: sweetness = [5,6,7,8,9,1,2,3,4], k = 8
Output: 1
Explanation: There is only one way to cut the bar into 9 pieces.
Example 3:

Input: sweetness = [1,2,2,1,2,2,1,2,2], k = 2
Output: 5
Explanation: You can divide the chocolate to [1,2,2], [1,2,2], [1,2,2]


Constraints:

0 <= k < sweetness.length <= 104
1 <= sweetness[i] <= 105
*/

class Solution {
public:
    int countCuts(vector<int>& sweetness, int maxSweet) {
        int cnt = 0, sum = 0;

        for(int sweet: sweetness) {
            sum += sweet;
            if(sum>=maxSweet) {
                sum = 0;
                cnt++;
            }
        }

        return cnt;
    }

    int maximizeSweetness(vector<int>& sweetness, int k) {
        int lo=sweetness[0], mid, hi=0, ans;

        for(int s: sweetness) {
            lo = min(lo, s);
            hi += s;
        }

        ans = hi;

        while(lo<=hi) {
            mid = (hi+lo)/2;
            int cuts = countCuts(sweetness, mid);
            if(cuts<=k) {
                hi = mid-1;
            } else {
                ans = mid;
                lo = mid+1;
            }
        }

        return ans;

    }
};
