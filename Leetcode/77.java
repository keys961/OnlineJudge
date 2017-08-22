import java.util.*;

public class Solution
{
    private List<List<Integer>> lists = new ArrayList<>();

    private void getCombination(int n, int k, int index, List<Integer> list)
    {
        if(list.size() == k)
        {
            lists.add(list);
            return;
        }

        for(int i = index + 1; i <= n; i++)
        {
            List<Integer> newList = new ArrayList<>(list);
            newList.add(i);
            getCombination(n, k, i, newList);
        }
    }

    public List<List<Integer>> combine(int n, int k)
    {
        getCombination(n, k, 0, new ArrayList<>());
        return lists;
    }
}