import java.util.*;

public class Solution
{
    List<List<Integer>> lists = new ArrayList<>();

    private void getSum(int[] candidates, int target, int index, List<Integer> list)
    {
        if(target == 0)
        {
            lists.add(list);
            return;
        }
        if(target < 0)
            return;

        for(int i = index; i < candidates.length; i++)
        {
            if(candidates[i] > target)
                return;
            List<Integer> list1 = new ArrayList<>(list);
            list1.add(candidates[i]);
            getSum(candidates, target - candidates[i], i, list1);
        }
    }


    public List<List<Integer>> combinationSum(int[] candidates, int target)
    {
        if(candidates.length == 0)
            return lists;
        Arrays.sort(candidates);
        getSum(candidates, target, 0, new ArrayList<Integer>());
        return lists;
    }
}