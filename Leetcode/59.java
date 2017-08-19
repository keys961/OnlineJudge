public class Solution
{

    private int[] directionX = new int[]{0, 1, 0, -1};
    private int[] directionY = new int[]{1, 0, -1, 0};

    public int[][] generateMatrix(int n)
    {
        int[][] result = new int[n][n];
        int x = 0, y = 0, p = 0;
        for(int i = 1; i <= n * n; i++)
        {
            result[x][y] = i;
            if(x + directionX[p] < 0 || x + directionX[p] >= n ||
                    y + directionY[p] < 0 || y + directionY[p] >= n
                || result[x + directionX[p]][y + directionY[p]] != 0)
                p = (p + 1) % 4;
            x += directionX[p];
            y += directionY[p];
        }

        return result;
    }
}