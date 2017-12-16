class Solution 
{
    public int arrayPairSum(int[] nums) 
    {
        int cnt = 0;
        Arrays.sort(nums);
        for(int i = 0; i < nums.length; i += 2)
            cnt += nums[i];
        
        return cnt;
    }
}