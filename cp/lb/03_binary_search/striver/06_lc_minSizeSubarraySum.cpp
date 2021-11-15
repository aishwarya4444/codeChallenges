/*
https://leetcode.com/problems/minimum-size-subarray-sum/

Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.



Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0


Constraints:

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 105


Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).
*/

class Solution {
public:
    // O(N lg N) using binary search
    int getMaxSum(vector<int> &nums, int len) {
        int sum=0, start=0, end=0, N=nums.size(), maxSum=0;

        while(end<N) {
            sum += nums[end];
            if(end-start+1==len) {
                maxSum = max(maxSum, sum);
                sum -= nums[start];
                start++;
            }
            end++;
        }

        return maxSum;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int lo=1, mid, hi=nums.size();

        while(lo<=hi) {
            mid = (lo+hi)/2;
            int sum = getMaxSum(nums, mid);
            if(sum>=target) {
                ans = mid;
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }

        return ans==INT_MAX ? 0 : ans;

    }

    /*
    // O(N) using sliding window
    int minSubArrayLen(int target, vector<int>& nums) {
        int start=0, end=0, N=nums.size(), len=INT_MAX, sum=0;

        while(end<N) {
            sum += nums[end];
            while(sum>=target) {
                len = min(len, end-start+1);
                sum -= nums[start];
                start++;
            }
            end++;
        }

        return len==INT_MAX ? 0 : len;

    }
    */
};
