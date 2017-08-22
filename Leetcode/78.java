import java.util.*;

public class Solution
{
    private List<List<Integer>> lists = new ArrayList<>();

    private void getCombination(int[] nums, int index, List<Integer> list)
    {
        if(list.size() > nums.length)
            return;
        if(list.size() <= nums.length)
            lists.add(list);

        for(int i = index + 1; i < nums.length; i++)
        {
            List<Integer> newList = new ArrayList<>(list);
            newList.add(nums[i]);
            getCombination(nums, i, newList);
        }
    }

    public List<List<Integer>> subsets(int[] nums)
    {
        getCombination(nums, -1, new ArrayList<>());
        return lists;
    }
}