public class Solution
{
    public int findPeakElement(int[] nums)
    {
//        for(int i = 0; i < nums.length - 1; i++)
//        {
//            if(nums[i + 1] < nums[i])
//                return i;
//        }
//        return nums.length - 1;

        int low = 0, up = nums.length - 1;
        while(low < up)
        {
            int mid = (low + up) / 2;
            if(nums[mid] < nums[mid + 1])
                low = mid + 1;
            else
                up = mid;
        }
        return low;

    }
}