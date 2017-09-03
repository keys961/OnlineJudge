public class Solution
{
    public int rob(int[] nums)
    {
        if(nums.length == 0)
            return 0;
        if(nums.length == 1)
            return nums[0];

        int[] dp1 = new int[nums.length + 1];
        int[] dp2 = new int[nums.length + 1];

        dp1[1] = nums[0];
        dp2[2] = nums[1];

        for(int i = 2; i < nums.length; i++)
        {
            dp1[i] = Math.max(dp1[i - 1], nums[i - 1] + dp1[i - 2]);
            dp2[i + 1] = Math.max(dp2[i], nums[i] + dp2[i - 1]);
        }

        return Math.max(dp1[nums.length - 1], dp2[nums.length]);
    }
}