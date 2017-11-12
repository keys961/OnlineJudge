class Solution
{
    public int integerBreak(int n)
    {
        int[] dp = new int[n + 1];
        dp[0] = 0; dp[1] = 1;
        
        for(int i = 2; i <= n; i++)
        {
            int maxProduct = 0;
            for(int j = 1; j < i; j++)
            {
                if(dp[j] * dp[i - j] > maxProduct)
                    maxProduct = dp[i - j] * dp[j];
                if(j * (i - j) > maxProduct) //another cases, exceptions
                    maxProduct = j * (i - j);
                if(j * dp[i - j] > maxProduct)
                    maxProduct = j * dp[i - j];
            }
            dp[i] = maxProduct;
        }
        
        return dp[n];
    }
}