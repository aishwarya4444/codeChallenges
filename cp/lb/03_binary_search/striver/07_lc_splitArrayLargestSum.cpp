/*
https://leetcode.com/problems/split-array-largest-sum/

Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.

Write an algorithm to minimize the largest sum among these m subarrays.



Example 1:

Input: nums = [7,2,5,10,8], m = 2
Output: 18
Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], m = 2
Output: 9
Example 3:

Input: nums = [1,4,4], m = 3
Output: 4


Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 106
1 <= m <= min(50, nums.length)
*/

class Solution {
public:
    int countSubarrays(vector<int>& nums, int maxSum) {
        int cnt = 1, sum = 0;

        for(int num: nums) {
            sum += num;
            if(sum>maxSum) {
                sum = num;
                cnt++;
            }
        }

        return cnt;
    }

    int splitArray(vector<int>& nums, int m) {
        int lo=0, mid, hi=0, ans=0;

        for(int num: nums) {
            lo = max(lo, num);
            hi += num;
        }

        ans = hi;

        while(lo<=hi) {
            mid = lo+(hi-lo)/2;
            int cnt = countSubarrays(nums, mid);
            if(cnt>m) {
                lo = mid+1;
            } else {
                hi = mid-1;
                ans = mid;
            }
        }

        return ans;
    }
};
