class Solution 
{
    public int pivotIndex(int[] nums)
    {
        if(nums.length <= 0)
            return -1;

        int[] left = new int[nums.length];
        int[] right = new int[nums.length];

        for(int i = 0 ; i < nums.length; i++)
        {
            if(i == 0)
            {
                left[i] = nums[i];
                right[nums.length - 1 - i] = nums[nums.length - 1 - i];
            }
            else
            {
                left[i] = left[i - 1] + nums[i];
                right[nums.length - 1 - i] = right[nums.length - i] + nums[nums.length - 1 - i];
            }
        }

        for(int i = 0; i < nums.length; i++)
        {
            if(left[i] == right[i])
                return i;
        }
        return  -1;
    }
}