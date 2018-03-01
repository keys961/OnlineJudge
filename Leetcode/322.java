class Solution 
{
    public int coinChange(int[] coins, int amount) 
    { 
//         //backpacket
//         int[] dp = new int[amount + 1];
//         Arrays.fill(dp, -1);
//         dp[0] = 0;
        
//         for(int i = 0; i <= amount; i++)
//         {
//             for(int coin : coins)
//             {
//                 if(i >= coin && dp[i - coin] >= 0)
//                     dp[i] = dp[i] > 0 ? Math.min(dp[i], dp[i - coin] + 1) : dp[i - coin] + 1;
//             }
//         }
        
//         return dp[amount];
        
        
        int[][] dp = new int[coins.length + 1][amount + 1];
        Arrays.fill(dp[0], -1);
        for(int i = 0; i <= coins.length; i++)
            dp[i][0] = 0;
        
        for(int i = 1; i <= coins.length; i++)
        {
            int coin = coins[i - 1];
            for(int j = 1; j <= amount; j++)
            {
                if(j < coin)
                    dp[i][j] = dp[i - 1][j];
                else if(j == coin)
                    dp[i][j] = 1;
                else
                {
                    dp[i][j] = Math.min(dp[i][j - coin] + 1, dp[i - 1][j]);
                    if(dp[i][j] <= 0)
                    {
                        if(dp[i][j - coin] + 1 > 0)
                            dp[i][j] = dp[i][j - coin] + 1;
                        else if(dp[i - 1][j] > 0)
                            dp[i][j] = dp[i - 1][j];
                        else
                            dp[i][j] = -1;
                    }
                }
            }
        }
        
        return dp[coins.length][amount];
    }
}