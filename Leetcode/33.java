import java.util.*;

public class Solution
{
    public int search(int[] nums, int target)
    {
        // Binary Search
        int low = 0, up = nums.length - 1, mid;
        //Get pivot
        while(low < up)
        {
            mid = (low + up) / 2;
            if(nums[mid] > nums[up])
                low = mid + 1;
            else
                up = mid;
        }
        //Pivot is up
        int index = Arrays.binarySearch(nums, 0, up, target);
        if(index < 0)
            index = Arrays.binarySearch(nums, up, nums.length, target);

        return index < 0 ? -1 : index;
    }
}