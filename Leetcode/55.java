public class Solution
{

    public boolean canJump(int[] nums)
    {
        int len = nums.length;
        if(len == 1)
            return true;

        if(nums[0] >= nums.length - 1)
            return true;

        int index = len - 1;
        for(int i = len - 2; i >= 0; i--)
        {
            if(nums[i] >= index - i)
                index = i;
        }

        return index == 0;
    }
}