/*
https://leetcode.com/problems/target-sum/
 */

// very important case
// handling of 0 value in array
// it can contribute in 2 ways

class Solution {
    public int findTargetSumWays(int[] nums, int S) {
        int sum = 0;

        for(int num: nums) {
            sum += num;
        }

        if(sum < S) {
            return 0;
        }

        S += sum;

        if(S%2 != 0) {
            return 0;
        }

        S /= 2;
        int r, c, N=nums.length;
        int[][] dp = new int[N][S+1];

        // important case
        for(r=0; r<N; r++) {
            if(nums[r]==0) {
                dp[r][0] = r==0 ? 2 : 2*dp[r-1][0];
            } else {
                dp[r][0] = r==0 ? 1 : dp[r-1][0];
            }
        }

        for(c=1; c<=S; c++) {
            dp[0][c] = c==nums[0] ? 1 : 0;
        }

        for(r=1; r<N; r++) {
            for(c=1; c<=S; c++) {
                dp[r][c] = dp[r-1][c];
                if(c>=nums[r]) {
                    dp[r][c] += dp[r-1][c-nums[r]];
                }
            }
        }

        return dp[N-1][S];

    }
}