/*
* https://leetcode.com/problems/partition-equal-subset-sum/
* */

// more memory
class Solution {
    public boolean canPartition(int[] nums) {
        int sum=0;

        for(int num: nums) {
            sum += num;
        }

        if(sum%2 != 0) {
            return false;
        }

        int r, c, N=nums.length, S=sum/2;
        boolean dp[][] = new boolean[N][S+1];

        for(r=0; r<N; r++) {
            dp[r][0] = true;
        }

        for(c=1; c<=S; c++) {
            dp[0][c] = c==nums[0];
        }

        for(r=1; r<N; r++) {
            for(c=1; c<=S; c++) {
                dp[r][c] = dp[r-1][c];
                if(dp[r][c]==false && c>=nums[r]) {
                    dp[r][c] = dp[r-1][c-nums[r]];
                }
            }
        }

        return dp[N-1][S];
    }
}


// optimised
class Solution {
    public boolean canPartition(int[] nums) {
        int sum=0;

        for(int num: nums) {
            sum += num;
        }

        if(sum%2 != 0) {
            return false;
        }

        int r, c, N=nums.length, S=sum/2;
        boolean dp[][] = new boolean[2][S+1];

        for(r=0; r<2; r++) {
            dp[r][0] = true;
        }

        for(c=1; c<=S; c++) {
            dp[0][c] = c==nums[0];
        }

        for(r=1; r<N; r++) {
            for(c=1; c<=S; c++) {
                dp[r%2][c] = dp[(r-1)%2][c];
                if(dp[r%2][c]==false && c>=nums[r]) {
                    dp[r%2][c] = dp[(r-1)%2][c-nums[r]];
                }
            }
        }

        return dp[(N-1)%2][S];
    }
}