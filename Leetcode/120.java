import java.util.*;

public class Solution
{
    public int minimumTotal(List<List<Integer>> triangle)
    {
        int[][] sum = new int[triangle.size() + 1][triangle.size() + 1];

        sum[0][0] = triangle.get(0).get(0);

        for(int i = 1; i < triangle.size(); i++)
        {
            for(int j = 0; j <= i; j++)
            {
                if(j == 0)
                    sum[i][j] = sum[i - 1][0] + triangle.get(i).get(j);
                else if(j == i)
                    sum[i][j] = sum[i - 1][i - 1] + triangle.get(i).get(j);
                else
                    sum[i][j] = triangle.get(i).get(j)
                            + Math.min(sum[i - 1][j - 1], sum[i - 1][j]);
            }
        }
        int min = Integer.MAX_VALUE;
        for(int i = 0; i < triangle.size(); i++)
            if(sum[triangle.size() - 1][i] < min)
                min = sum[triangle.size() - 1][i];
        return min;
    }
}