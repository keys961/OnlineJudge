import java.util.*;

public class Solution
{
    public List<Integer> majorityElement(int[] nums)
    {
        List<Integer> list = new ArrayList<>();
        HashMap<Integer, Integer> map = new HashMap<>();
        if(nums.length == 0)
            return list;

        for(int i = 0; i < nums.length; i++)
        {
            if(map.containsKey(nums[i]))
                map.put(nums[i], map.get(nums[i]) + 1);
            else
                map.put(nums[i], 1);
        }

        Set<Map.Entry<Integer, Integer>> entries = map.entrySet();
        for(Map.Entry<Integer, Integer> entry : entries)
            if(entry.getValue() > nums.length / 3)
                list.add(entry.getKey());
        return list;
    }
}