class Solution 
{
    private int[] countZeroAndOne(String s)
    {
        int[] res = new int[2];
        for(int i = 0; i < s.length(); i++)
        {
            switch (s.charAt(i))
            {
                case '0': res[0]++; break;
                case '1': res[1]++; break;
            }
        }
        return res;
    }


    public int findMaxForm(String[] strs, int m, int n) //0-1 knapstack
    {
        int[][][] dp = new int[strs.length + 1][m + 1][n + 1];
        int[] cnt;
        
        for(int i = 1; i <= strs.length; i++) //index of strs + 1
        {
            for(int j = 0; j <= m; j++)
            {
                for(int k = 0; k <= n; k++)
                {
                    cnt = countZeroAndOne(strs[i - 1]);
                    if(cnt[0] > j || cnt[1] > k)
                        dp[i][j][k] = dp[i - 1][j][k];
                    else
                        dp[i][j][k] = Math.max(dp[i - 1][j][k],
                                dp[i - 1][j - cnt[0]][k - cnt[1]] + 1);
                }
            }
        }
        
        return dp[strs.length][m][n];
    }
}