import java.util.*;

public class Solution
{
    public List<Integer> getRow(int rowIndex)
    {
        List<Integer> lastList = new ArrayList<>();

        for(int i = 0; i <= rowIndex; i++)
        {
            List<Integer> list = new ArrayList<>();
            for(int j = 1; j <= i + 1; j++)
            {
                if(j == 1 || j == i + 1)
                    list.add(1);
                else
                    list.add(lastList.get(j - 1)
                        + lastList.get(j - 2));
            }
            lastList = list;
        }
        return lastList;
    }
}