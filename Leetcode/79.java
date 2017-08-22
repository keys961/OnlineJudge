import javafx.util.Pair;
import java.util.*;

public class Solution
{

    private int[] directionX = new int[]{0, 1, 0, -1};
    private int[] directionY = new int[]{1, 0, -1, 0};

    private boolean flag = false;

    private void dfs(char[][] board, boolean[][] visited, String word, int x, int y, int index)
    {
        if(flag)
            return;
        if(word.charAt(index) == board[x][y])
        {
            if(index == word.length() - 1)
            {
                flag = true;
                return;
            }
            visited[x][y] = true;
            for(int i = 0; i < 4; i++)
            {
                int newX = x + directionX[i];
                int newY = y + directionY[i];
                if(newX >= 0 && newX < board.length && newY >= 0 && newY < board[0].length && !visited[newX][newY])
                    dfs(board, visited, word, newX, newY, 1 + index);
            }
            visited[x][y] = false;
        }
    }

    public boolean exist(char[][] board, String word)
    {
        int m = board.length;
        if(m == 0)
            return false;
        if(word.length() == 0)
            return true;
        int n = board[0].length;
        boolean[][] visited = new boolean[board.length][board[0].length];
        List<Pair<Integer, Integer>> firstChars = new ArrayList<>();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
                if(board[i][j] == word.charAt(0))
                    firstChars.add(new Pair<>(i, j));
        }
        if(firstChars.size() == 0)
            return false;

        for(Pair<Integer, Integer> pair : firstChars)
        {
            if(flag)
               return true;
            dfs(board, visited, word, pair.getKey(), pair.getValue(), 0);
        }
        return flag;
    }
}