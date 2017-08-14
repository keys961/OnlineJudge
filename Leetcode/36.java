public class Solution
{
    private boolean checkRowColumn(char[][] board, int n)
    {
        boolean[] checkedRow = new boolean[10];
        boolean[] checkedColumn = new boolean[10];

        for(int i = 0; i < 9; i++)
        {
            if(board[n][i] != '.')
            {
                if(checkedRow[board[n][i] - '0'])
                    return false;
                checkedRow[board[n][i] - '0'] = true;
            }
            if(board[i][n] != '.')
            {
                if(checkedColumn[board[i][n] - '0'])
                    return false;
                checkedColumn[board[i][n] - '0'] = true;
            }
        }
        return true;
    }

    private boolean checkSquare(char[][] board, int x, int y)
    {
        boolean[] checked = new boolean[10];
        for(int i = x; i < x + 3; i++)
        {
            for(int j = y; j < y + 3; j++)
            {
                if(board[i][j] != '.')
                {
                    if(checked[board[i][j] - '0'])
                        return false;
                    checked[board[i][j] - '0'] = true;
                }
            }
        }
        return true;
    }


    public boolean isValidSudoku(char[][] board)
    {
        boolean status = true;
        for(int i = 0; i < 9; i++)
            status &= checkRowColumn(board, i);
        if(!status)
            return false;
        for(int i = 0; i < 9; i += 3)
            for(int j = 0; j < 9; j += 3)
                status &= checkSquare(board, i, j);
        return status;
    }
}