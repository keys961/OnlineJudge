public class Solution
{
    public int uniquePaths(int m, int n)
    {
        int[][] matrix = new int[m + 1][n + 1];
        if(m == 0 || n == 0)
            return 0;

        matrix[1][1] = 1;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(!(i == 1 && j == 1))
                    matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];

        return matrix[m][n];
    }
}