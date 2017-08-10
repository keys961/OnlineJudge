public class Solution 
{
    public String longestPalindrome(String s)
    {   //P(i,j) = P(i+1,j-1) while S[i] == S[j]
        int len = s.length();
        String res = new String("");
        boolean[][] dp = new boolean[len][len];
        for (int i = len - 1; i >= 0; i--)
        {
            for (int j = i; j < len; j++)
            {
                if(s.charAt(i) == s.charAt(j))
                {
                    if(j - i < 3)
                        dp[i][j] = true;
                    else
                        dp[i][j] = dp[i + 1][j - 1];
                }
                else
                    dp[i][j] = false;
                if (dp[i][j] && j - i + 1 > res.length())
                    res = s.substring(i, j + 1);
            }
        }
        return res;
    }
}