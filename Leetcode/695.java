class Solution
{
    boolean[][] visited;
    
    int maxSquere = 0;
    
    int tempSquere = 0;

    private void dfs(int[][] grid, int i, int j)
    {
        visited[i][j] = true;
        tempSquere++;
        if(i > 0 && grid[i - 1][j] == 1 && !visited[i - 1][j])
            dfs(grid, i - 1, j);
        if(i < grid.length - 1 && grid[i + 1][j] == 1 && !visited[i + 1][j])
            dfs(grid, i + 1, j);
        if(j > 0 && grid[i][j - 1] == 1 && !visited[i][j - 1])
            dfs(grid, i, j - 1);
        if(j < grid[0].length - 1 && grid[i][j + 1] == 1 && !visited[i][j + 1])
            dfs(grid, i, j + 1);
    }

    public int maxAreaOfIsland(int[][] grid)
    {
        if(grid.length == 0 || grid[0].length == 0)
            return 0;
        visited = new boolean[grid.length][grid[0].length];
        
        for(int i = 0; i < grid.length; i++)
        {
            for(int j = 0; j < grid[0].length; j++)
            {
                if(!visited[i][j])
                {
                    visited[i][j] = true;
                    if(grid[i][j] == 1)
                    {
                        tempSquere = 0;
                        dfs(grid, i, j);
                        if(tempSquere > maxSquere)
                            maxSquere = tempSquere;
                    }
                }
            }
        }
        return maxSquere;
    }
}