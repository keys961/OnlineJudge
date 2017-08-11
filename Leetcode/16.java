public class Solution
{
    public int threeSumClosest(int[] nums, int target)
    {
        Arrays.sort(nums);
        long minDiff = Long.MAX_VALUE;
        int sum = 0, res = 0; //Final res
        int low, up;
        for(int i = 0; i < nums.length - 2; i++)
        {
            low = i + 1;
            up = nums.length - 1;
            while(low < up)
            {
                sum = nums[i] + nums[low] + nums[up];
                if (sum < target)
                    low++;
                else
                    up--;
                if(Math.abs(sum - target) < minDiff)
                {
                    res = sum;
                    minDiff = Math.abs(sum - target);
                }
            }
        }
        return res;
    }
}