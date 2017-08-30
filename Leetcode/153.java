public class Solution
{
//    private int helper(int[] nums, int low, int up)
//    {
//        if(low == up)
//            return nums[low];
//        int mid = (low + up) / 2;
//        return Math.min(helper(nums, low, mid),
//                helper(nums, mid + 1, up));
//    }

    public int findMin(int[] nums)
    {
//        if(nums.length == 0)
//            return 0;
//        return helper(nums, 0, nums.length - 1);
        int low = 0, up = nums.length - 1;
        while(low < up)
        {
            int mid = (low + up) / 2;
            if(nums[mid] > nums[up])
                low = mid + 1;
            else
                up = mid;
        }
        return nums[low];
    }
}