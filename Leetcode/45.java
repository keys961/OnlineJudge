class Solution 
{
    public int jump(int[] nums)
    {
        if(nums.length <= 1)
            return 0;
        int index = 0;
        int cnt = 0;
        while(index < nums.length)
        {
            if(index + nums[index] >= nums.length - 1)
            {
                cnt++;
                break;
            }

            int nextIndex = index;
            int maxStepDiff = Integer.MAX_VALUE;

            for(int i = index + 1; i <= index + nums[index]; i++)
            {
                if(nums.length - 1 - i - nums[i] <= maxStepDiff)
                {
                    nextIndex = i;
                    maxStepDiff = nums.length - 1 - i - nums[i];
                }
            }

            cnt++;
            index = nextIndex;
        }
        return cnt;
    }
}