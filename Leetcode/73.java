import java.util.*;

public class Solution
{
    public void setZeroes(int[][] matrix)
    {
        if(matrix.length == 0)
            return;
        boolean[] columns = new boolean[matrix[0].length]; // Set flag on column
        for(int i = 0; i < matrix.length; i++)
        {
            boolean flag = false;
            for(int j = 0; j < matrix[0].length; j++)
            {
                if(matrix[i][j] == 0)
                {
                    columns[j] = true;
                    flag = true;
                }
            }
            if(flag)
                Arrays.fill(matrix[i], 0, matrix[i].length, 0);
        }
        for(int j = 0; j < columns.length; j++)
        {
            if(columns[j])
            {
                for(int i = 0; i < matrix.length; i++)
                    matrix[i][j] = 0;
            }
        }
    }
}