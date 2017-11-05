class Solution 
{
    public boolean canPartition(int[] nums)
    {
        long sum = 0;
        for(int n : nums)
            sum += n;

        if(sum % 2 != 0)
            return false;
        sum /= 2;

        long[][] dp = new long[nums.length + 1][(int)sum + 1];

        for(int i = 1; i <= nums.length; i++)
        {
            for(int j = 1; j <= sum; j++) //O-1 Knapstack problem 
            {
                if(nums[i - 1] <= j) //Load value sum / 2 =>   dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i])
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - nums[i - 1]] + nums[i - 1]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[nums.length][(int)sum] == sum;
    }
}