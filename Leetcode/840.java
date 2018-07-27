class Solution 
{
    public int numMagicSquaresInside(int[][] grid) 
    {
        int x = grid.length;
        int y = grid[0].length;
        int res = 0;
        for(int i = 0; i <= x - 3; i++)
        {
            for(int j = 0; j <= y - 3; j++)
                if(judge(grid, i, j))
                    res++;
        }
        
        return res;
    }
    
    private boolean judge(int[][] grid, int x, int y)
    {
        int sum = grid[x][y] + grid[x + 1][y + 1] + grid[x + 2][y + 2];
        if(sum != grid[x][y + 2] + grid[x + 1][y + 1] + grid[x + 2][y])
            return false;
        
        for(int i = 0; i < 3; i++)
        {
            int temp1 = 0;
            for(int j = 0; j < 3; j++)
            {
                if(grid[x + i][y + j] < 1 || grid[x + i][y + j] > 9)
                    return false;
                temp1 += grid[x + i][y + j];
            }
            if(temp1 != sum)
                return false;
        }
        
        for(int i = 0; i < 3; i++)
        {
            int temp2 = 0;
            for(int j = 0; j < 3; j++)
                temp2 += grid[x + j][y + i];
            if(temp2 != sum)
                return false;
        }
        
        return true;
    }
}