public class Solution
{
    private int[] directionX = new int[]{0, -1, 0, 1};

    private int[] directionY = new int[]{-1, 0, 1, 0};

    private void dfs(char[][] grid, boolean[][] visited, int i, int j)
    {

        for(int k = 0; k < 4; k++)
        {
            int newX = i + directionX[k];
            int newY = j + directionY[k];

            if(newX >= 0 && newX < grid.length
                    && newY >= 0 && newY < grid[0].length)
            {
                if(!visited[newX][newY])
                {
                    visited[newX][newY] = true;
                    if(grid[newX][newY] == '1')
                        dfs(grid, visited, newX, newY);
                }
            }
        }
    }

    public int numIslands(char[][] grid)
    {
        if(grid.length == 0 || grid[0].length == 0)
            return 0;

        boolean[][] visited = new boolean[grid.length][grid[0].length];
        int count = 0;

        for(int i = 0; i < grid.length; i++)
        {
            for(int j = 0; j < grid[0].length; j++)
            {
                if(!visited[i][j] && grid[i][j] == '1')
                {
                    visited[i][j] = true;
                    dfs(grid, visited, i, j);
                    count++;
                }
            }
        }
        return count;
    }
}