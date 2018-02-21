class Solution
{
    public int maxProduct(int[] nums) 
    {
        int[] dpPositive = new int[nums.length + 1];//from 0-n max product = max(nums[i], maxProduct[i-1]*nums[i], minProduct[i-1]*nums[i])
        int[] dpNegative = new int[nums.length + 1];//from 0-n min product = min(nums[i], maxProduct[i-1]*nums[i], minProduct[i-1]*nums[i])
        dpPositive[0] = dpNegative[0] = nums[0];
        int result = nums[0];
        for(int i = 1; i < nums.length; i++)
        {
            dpPositive[i] = Math.max(nums[i], Math.max(dpPositive[i - 1] * nums[i], dpNegative[i - 1] * nums[i]));
            dpNegative[i] = Math.min(nums[i], Math.min(dpPositive[i - 1] * nums[i], dpNegative[i - 1] * nums[i]));
            if(dpPositive[i] > result)
                result = dpPositive[i];
        }
        
        return result;
    }
}