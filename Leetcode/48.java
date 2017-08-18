public class Solution
{
    /**
     * Reference:
     * clockwise rotate
     * first reverse up to down, then swap the symmetry
     * 1 2 3     7 8 9     7 4 1
     * 4 5 6  => 4 5 6  => 8 5 2
     * 7 8 9     1 2 3     9 6 3
     **/

    public void rotate(int[][] matrix)
    {
        int size = matrix.length;
        for(int j = 0; j < size; j++)//Reverse
        {
            for(int i = 0; i < size / 2; i++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[size - i - 1][j];
                matrix[size - i - 1][j] = temp;
            }
        }
        for(int i = 0; i < size; i++)
        {
            for(int j = i + 1; j < size; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
}