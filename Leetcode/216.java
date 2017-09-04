import java.util.*;

public class Solution
{
    private List<List<Integer>> lists = new ArrayList<>();

    private void helper(int k, int n, int index, List<Integer> list)
    {
        if(k == 0)
        {
            if(n == 0)
                lists.add(list);
            return;
        }

        if(n < 0 || k < 0)
            return;

        for(int i = index + 1; i <= 9; i++)
        {
            List<Integer> newList = new ArrayList<>(list);
            newList.add(i);
            helper(k - 1, n - i, i, newList);
        }
    }

    public List<List<Integer>> combinationSum3(int k, int n)
    {
        for(int i = 1; i <= 9; i++)
        {
            List<Integer> list = new ArrayList<>();
            list.add(i);
            helper(k - 1, n - i, i, list);
        }
        return lists;
    }
}