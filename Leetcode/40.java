import java.util.*;

public class Solution
{

    private List<List<Integer>> lists = new ArrayList<>();

    private void getCombination(int[] candidates, int index, int target, List<Integer> list)
    {
        List<Integer> newList = new ArrayList<>(list);
        if(target == 0)
        {
            newList.add(candidates[index]);
            if(!lists.contains(newList))
                lists.add(newList);
            return;
        }

        if(target < 0)
            return;

        if(index != -1)
            newList.add(candidates[index]);

        for(int i = index + 1; i < candidates.length; i++)
        {
            getCombination(candidates, i, target - candidates[i], newList);
        }

    }

    public List<List<Integer>> combinationSum2(int[] candidates, int target)
    {
        if(candidates.length == 0)
            return lists;

        Arrays.sort(candidates);
        List<Integer> list = new ArrayList<>();
        getCombination(candidates, -1, target, list);

        return lists;
    }
}