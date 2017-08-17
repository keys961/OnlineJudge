public class Solution
 {
    public int[] searchRange(int[] nums, int target)
    {
        int[] range = new int[]{-1, -1};

        int pivot = Arrays.binarySearch(nums, target);
        if(pivot < 0)
            return range;
        range[0] = range[1] = pivot;
        int low = pivot, up = pivot;
        while(low >= 0)
        {
            low = Arrays.binarySearch(nums, 0, low, target);
            if(low >= 0)
                range[0] = low;
        }

        while(up >= 0)
        {
            up = Arrays.binarySearch(nums, up + 1, nums.length, target);
            if(up >= 0)
                range[1] = up;
        }

        return range;
    }
}