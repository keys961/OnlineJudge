import java.util.*;

public class Solution
{
    public List<String> summaryRanges(int[] nums)
    {
        List<String> list = new ArrayList<>();
        if(nums.length == 0)
            return list;
        if(nums.length == 1)
        {
            list.add(Integer.toString(nums[0]));
            return list;
        }

        int last = nums[0];
        int max = nums[0];
        int min = nums[0];
        for(int i = 1; i < nums.length; i++)
        {
            if(nums[i] - last != 1)
            {
                if(max == min)
                    list.add(Integer.toString(max));
                else
                    list.add(Integer.toString(min) + "->" + Integer.toString(max));
                min = max = last = nums[i];
                if(i == nums.length - 1)
                    list.add(Integer.toString(max));
            }
            else
            {
                last = nums[i];
                max = nums[i];
                if(i == nums.length - 1)
                    list.add(Integer.toString(min) + "->" + Integer.toString(max));
            }
        }
        return list;
    }
}