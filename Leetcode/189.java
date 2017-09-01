class Solution 
{
    public void rotate(int[] nums, int k)
    {
        k = k % nums.length;
        if(k == 0)
            return;
        int pivotIndex = nums.length - k;
        int[] removed = new int[k];
        int[] previous = new int[nums.length - k];
        for(int i = 0; i < nums.length - k; i++)
            previous[i] = nums[i];
        
        for(int i = pivotIndex; i < nums.length; i++)
            removed[i - pivotIndex] = nums[i];

        for(int i = k; i < nums.length; i++)
            nums[i] = previous[i - k];

        for(int i = 0; i < k; i++)
            nums[i] = removed[i];
    }
}