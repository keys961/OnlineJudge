import java.util.*;

public class Solution
{
    public void sortColors(int[] nums)
    {
        int[] count = new int[3];
        for(int i = 0; i < nums.length; i++)
            count[nums[i]]++;
        Arrays.fill(nums, 0, count[0], 0);
        Arrays.fill(nums, count[0], count[0] + count[1], 1);
        Arrays.fill(nums, count[0] + count[1], nums.length, 2);
    }
}