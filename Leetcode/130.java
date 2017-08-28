//BFS & Disjoint Set
import java.util.*;

public class Solution
{
    private boolean isSame(int[] disjointSet, int a, int b)
    {
        return find(disjointSet, a) == find(disjointSet, b);
    }

    private int find(int[] disjointSet, int a)
    {
        while(disjointSet[a] >= 0)
            a = disjointSet[a];
        return a;
    }

    private void union(int[] disjointSet, int a, int b, boolean edge)
    {
        int indexA = find(disjointSet, a);
        int indexB = find(disjointSet, b);
        if(indexA != indexB)
            disjointSet[indexB] = indexA;
        if(edge || disjointSet[indexA] == -2)
            disjointSet[indexA] = -2;
        else
            disjointSet[indexA] = -3;
    }

    public void solve(char[][] board)
    {
        int[] directionX = new int[]{0, -1, 0, 1};
        int[] direcitonY = new int[]{-1, 0, 1, 0};
        if(board.length == 0 || board[0].length == 0)
            return;
        int x = board.length, y = board[0].length;
        if(x == 1 || y == 1)
            return;

        boolean[] visited = new boolean[x * y];
        int[] disjointSet = new int[x * y];
        Queue<Integer> queue = new LinkedList<>();

        Arrays.fill(disjointSet, -1);

        for(int i = 1; i < x - 1; i++)
        {
            for(int j = 1; j < y - 1; j++)
            {
                if(board[i][j] == 'O' && !visited[i * y + j])
                {
                    queue.add(i * y + j);
                    visited[i * y + j] = true;
                    disjointSet[i * y + j] = -3;
                    while(!queue.isEmpty())
                    {
                        int temp = queue.poll();
                        int tempX = temp / y;
                        int tempY = temp % y;
                        for(int p = 0; p < 4; p++)
                        {
                            int newX = tempX + directionX[p];
                            int newY = tempY + direcitonY[p];
                            if(newX >= 0 && newY >= 0 && newY < y && newX < x && !visited[newX * y + newY] && board[newX][newY] == 'O')
                            {
                                boolean edge = false;
                                if(newX == 0 || newY == 0 || newX == x - 1 || newY == y - 1)
                                    edge = true;
                                queue.add(newX * y + newY);
                                visited[newX * y + newY] = true;
                                union(disjointSet, temp, newX * y + newY, edge);
                            }
                        }
                    }
                }
            }
        }

        for(int i = 1; i < x - 1; i++)
        {
            for(int j = 1; j < y - 1; j++)
            {
                if(disjointSet[find(disjointSet, i * y + j)] == -3)
                    board[i][j] = 'X';
            }
        }

    }
}