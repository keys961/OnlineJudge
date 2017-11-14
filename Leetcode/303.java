class NumArray
{
    private int[] dp;
    
    public NumArray(int[] nums)
    {
        dp = new int[nums.length];
        for(int i = 0; i < nums.length; i++)
        {
            if(i == 0)
                dp[i] = nums[i];
            else
                dp[i] = dp[i - 1] + nums[i];
        }
    }
    
    public int sumRange(int i, int j)
    {
        if(i == 0)
            return dp[j];
        return dp[j] - dp[i - 1];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */