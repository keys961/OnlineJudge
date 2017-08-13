public class Solution
{
    public int searchInsert(int[] nums, int target)
    {
        int low = 0, up = nums.length;
        int mid;
        if(nums.length == 0 || target <= nums[0])
            return 0;
        while(low < up)
        {
            mid = (low + up) / 2;
            if(nums[mid] == target)
                return mid;

            if(nums[mid] > target)
                up = mid;
            else
                low = mid + 1;
        }
        return up;
    }
}