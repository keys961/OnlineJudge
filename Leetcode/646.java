class Solution 
{
    //Longest Increasing Subsequence - PAT Top : The best peak shape
    private boolean isBigger(int[] a, int[] b)
    {
        return a[1] < b[0];
    }

    public int findLongestChain(int[][] pairs)
    {
        Arrays.sort(pairs, ((o1, o2) -> {
            if(o1[0] == o2[0])
                return o1[1] - o2[1];
            return o1[0] - o2[0];
        })); //sort

        int[] dp = new int[pairs.length + 1];
        dp[0] = 1;

        for(int i = 1; i < pairs.length; i++)
        {
            dp[i] = 1;
            for(int j = 0; j < i; j++)
            {
                if(isBigger(pairs[j], pairs[i]))
                {
                    if(dp[j] + 1 > dp[i])
                        dp[i] = dp[j] + 1;
                }
            }
        }
        
        return dp[pairs.length - 1];
    }
}