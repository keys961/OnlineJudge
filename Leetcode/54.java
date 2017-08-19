import java.util.*;

public class Solution
{

    private int[] directionX = new int[]{0, 1, 0, -1};
    private int[] directionY = new int[]{1, 0, -1, 0};

    public List<Integer> spiralOrder(int[][] matrix)
    {
        List<Integer> result = new LinkedList<>();

        int row = matrix.length;
        if(row == 0)
            return result;
        boolean[][] visited = new boolean[matrix.length][matrix[0].length];
        int column = matrix[0].length;
        int n = row * column;

        int x = 0, y = 0, p = 0;

        for(int i = 0; i < n; i++)
        {
            result.add(matrix[x][y]);
            visited[x][y] = true;
            if(x + directionX[p] < 0 || x + directionX[p] >= row ||
                    y + directionY[p] < 0 || y + directionY[p] >= column
                    || visited[x + directionX[p]][y + directionY[p]])
                p = (p + 1) % 4;
            x += directionX[p];
            y += directionY[p];
        }

        return result;
    }
}