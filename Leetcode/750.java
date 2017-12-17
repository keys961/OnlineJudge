class Solution 
{
    public int countCornerRectangles(int[][] grid)
    {
        int[][] dp = new int[grid.length][grid[0].length];

        Arrays.fill(dp[0], 0);
        for(int i = 0; i < dp.length; i++)
            dp[i][0] = 0;
        
        for(int i = 1; i < grid.length; i++)
        {
            for(int j = 1; j < grid[i].length; j++)
            {
                
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
                if(grid[i][j] == 1) 
                {
                    for (int x = i - 1; x >= 0; x--)
                    {
                        if(grid[x][j] == 1) 
                        {
                            for (int y = j - 1; y >= 0; y--) 
                            {
                                if(grid[x][y] == 1 && grid[i][y] == 1)
                                    dp[i][j]++;
                            }
                        }
                    }
                }
            }
        }
        
        return dp[grid.length - 1][grid[0].length - 1];
    }
}