import java.util.*;

public class Solution
{
    public List<List<Integer>> generate(int numRows)
    {
        List<List<Integer>> lists = new ArrayList<>();

        for(int i = 0; i < numRows; i++)
        {
            List<Integer> list = new ArrayList<>();
            for(int j = 1; j <= i + 1; j++)
            {
                if(j == 1 || j == i + 1)
                    list.add(1);
                else
                    list.add(lists.get(i - 1).get(j - 1)
                        + lists.get(i - 1).get(j - 2));
            }
            lists.add(list);
        }
        return lists;
    }
}