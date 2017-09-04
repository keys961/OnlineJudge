class Solution 
{
    public int minSubArrayLen(int s, int[] nums)
    {
        int low = 0, up = 0;
        int sum = 0;
        int len = Integer.MAX_VALUE;
        while(up < nums.length)
        {
            sum += nums[up];
            if(sum >= s)
            {
                if(up - low + 1 < len)
                    len = up - low + 1;
                low++;
                up = low;
                sum = 0;
                continue;
            }
            if(sum < 0) 
            {
                sum = 0;
                low = up + 1;
            }
            up++;
        }
        return len == Integer.MAX_VALUE ? 0 : len;
    }
}