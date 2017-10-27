class Solution 
{
    private int helper(int n, int[] nums)
    {
        int i = 0;
        for(; i < nums.length; i++)
            if(nums[i] == n)
                break;
        i++;
        for(; i < nums.length; i++)
        {
            if(nums[i] > n)
                return nums[i];
        }
        return -1;
    }
    
    public int[] nextGreaterElement(int[] nums1, int[] nums2)
    {
        int[] ans = new int[nums1.length];
        int i = 0;
        for(int n : nums1)
            ans[i++] = helper(n, nums2);
        return ans;
    }
}