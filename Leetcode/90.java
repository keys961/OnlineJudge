import java.util.*;

public class Solution
{
    List<List<Integer>> lists = new ArrayList<>();

    private void helper(int[] nums, int index, List<Integer> list)
    {
        if(list.size() > nums.length)
            return;
        if(list.size() <= nums.length)
        {
            if(!lists.contains(list))
                lists.add(list);
            //return;
        }
        for(int i = index + 1; i < nums.length; i++)
        {
//            if(index > 0 && nums[i] == nums[index])
//                continue;
            List<Integer> newList = new ArrayList<>(list);
            newList.add(nums[i]);
            helper(nums, i, newList);
        }
    }

    public List<List<Integer>> subsetsWithDup(int[] nums)
    {
        Arrays.sort(nums);
        helper(nums, -1, new ArrayList<Integer>());
        return lists;
    }
}