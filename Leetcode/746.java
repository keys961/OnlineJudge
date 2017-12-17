class Solution
{
   public int minCostClimbingStairs(int[] cost)
    {
        //getMinCost(cost, -1, 0);
        //getMinCost(cost, 1, 0);
        int[] dp = new int[cost.length + 1];
        if(cost.length <= 0)
            return 0;
        dp[0] = 0;
        dp[1] = 0;
        for(int i = 2; i <= cost.length; i++)
        {
            dp[i] = Math.min(dp[i - 1] + cost[i - 1],
                    dp[i - 2] + cost[i - 2]);
        }
        return dp[dp.length - 1];
    }
}