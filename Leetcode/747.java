class Solution
{
    public int dominantIndex(int[] nums) 
    {
        if(nums.length == 1)
            return 0;
        int max = -1, secondMax = -2;
        int index = 0;
        for(int i = 0; i < nums.length; i++)
        {
            if(nums[i] > max)
            {
                index = i;
                max = nums[i];
            }
        }
        
        for(int i = 0; i < nums.length; i++)
        {
            if(nums[i] > secondMax && nums[i] < max)
                secondMax = nums[i];
        }
        
        if(secondMax * 2 <= max)
            return index;
        return -1;
    }
}