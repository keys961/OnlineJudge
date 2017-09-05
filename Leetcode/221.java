public class Solution
{
    public int maximalSquare(char[][] matrix)
    {
        int x = matrix.length;
        if(x == 0)
            return 0;
        int y = matrix[0].length;
        if(y == 0)
            return 0;

        int maxVal = 0;
        int[][] dp = new int[x + 1][y + 1];
        for(int i = 1; i <= x; i++)
        {
            for(int j = 1; j <= y; j++)
            {
                if(matrix[i - 1][j - 1] == '1')
                {
                    dp[i][j] = Math.min(Math.min(dp[i - 1][j - 1],
                            dp[i][j - 1]), dp[i - 1][j]) + 1;
                    if(dp[i][j] > maxVal)
                        maxVal = dp[i][j];
                }
                else
                    dp[i][j] = 0;
            }
        }

        return maxVal * maxVal;
    }
}