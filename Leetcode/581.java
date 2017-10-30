class Solution 
{
    public int findUnsortedSubarray(int[] nums)
    {
        if(nums.length == 0)
            return 0;
        int[] copy;
        copy = Arrays.copyOf(nums, nums.length);
        Arrays.sort(copy);
        
        int left = 0, right = nums.length - 1;
        while(left < nums.length)
        {
            if(nums[left] != copy[left])
                break;
            left++;
        }
        
        while(0 <= right)
        {
            if(nums[right] != copy[right])
                break;
            right--;
        }
        if(left > right)
            return 0;
        return right - left + 1;
    }
}