/*
https://leetcode.com/problems/last-stone-weight-ii/
 */


class Solution {
    public int lastStoneWeightII(int[] stones) {
        int sum = 0;

        for(int stone: stones) {
            sum += stone;
        }

        int r, c, N=stones.length, S=sum/2, sum1=0, sum2=0;
        boolean[][] dp = new boolean[N][1+S];

        for(r=0; r<N; r++) {
            dp[r][0] = true;
        }

        for(c=1; c<=S; c++) {
            dp[0][c] = c==stones[0];
        }

        for(r=1; r<N; r++) {
            for(c=1; c<=S; c++) {
                if(dp[r-1][c]) {
                    dp[r][c] = dp[r-1][c];
                } else if(c>=stones[r]) {
                    dp[r][c] = dp[r-1][c-stones[r]];
                }
            }
        }

        for(r=N-1, c=S; c>=0; c--) {
            if(dp[r][c]) {
                sum1 = c;
                break;
            }
        }

        sum2 = sum-sum1;

        return Math.abs(sum1-sum2);

    }
}