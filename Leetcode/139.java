public class Solution
{
    public boolean wordBreak(String s, List<String> wordDict)
    {
        int length = s.length();
        if(length <= 0)
            return false;
        boolean[][] dp = new boolean[length + 1][length + 1];
        for(int step = 0; step <= length - 1; step++)
        {
            for(int i = 0; i < length - step; i++)
            {
                if(wordDict.contains(s.substring(i, i + step + 1)))
                {
                    dp[i][i + step] = true;
                    continue;
                }
                
                for(int j = i; j < i + step; j++)
                    dp[i][i + step] |= dp[i][j] && dp[j + 1][i + step]; 
            }
        }
        
        return dp[0][length - 1];
   }
}

// dp[n] = exist(dp[i] && dict.contain(s.substring(i, n))) i from 0 to n