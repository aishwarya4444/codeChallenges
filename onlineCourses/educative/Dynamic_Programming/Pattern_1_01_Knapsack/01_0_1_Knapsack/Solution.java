class Knapsack {

    public int solveKnapsack(int[] profits, int[] weights, int capacity) {
        if(capacity<=0 || weights.length==0 || profits.length==0) {
            return 0;
        }

        int[][] dp = new int[profits.length][capacity+1];
        int r, c, p1, p2;

        for(r=0; r<profits.length; r++) {
            dp[r][0] = 0;
        }

        for(c=1; c<=capacity; c++) {
            dp[0][c] = weights[0]<=capacity ? profits[0] : 0;
        }

        for(r=1; r<profits.length; r++) {
            for(c=1; c<=capacity; c++) {
                p1 = 0;
                p2 = 0;
                if(weights[r]<=c) {
                    p1 = profits[r]+dp[r-1][c-weights[r]];
                }
                p2 = dp[r-1][c];
                dp[r][c] = Math.max(p1, p2);
            }
        }

        return dp[profits.length-1][capacity];
    }

    public static void main(String[] args) {
        Knapsack ks = new Knapsack();
        int[] profits = {1, 6, 10, 16};
        int[] weights = {1, 2, 3, 5};
        int maxProfit = ks.solveKnapsack(profits, weights, 7);
        System.out.println("Total knapsack profit ---> " + maxProfit);
        maxProfit = ks.solveKnapsack(profits, weights, 6);
        System.out.println("Total knapsack profit ---> " + maxProfit);
    }
}