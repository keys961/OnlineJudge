class Solution 
{
    public boolean checkPossibility(int[] nums) 
    {
        int count = 0;
        
        for(int i = 0; i < nums.length - 1; i++)
        {
            if(nums[i] > nums[i + 1])
            {
                count++;
                
                if(i > 0 && nums[i + 1] < nums[i - 1]) // 3 4 2 3 -> 3 4 4 3
                    nums[i + 1] = nums[i];
                else // 3 4 3 x x -> 3 4 4 x x 
                    nums[i] = nums[i + 1];
            }
        }
        return count <= 1;
    }
}