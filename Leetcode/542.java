class Solution 
{
    class Position
    {
        int x;
        int y;
        Position(int x, int y)
        {
            this.x = x;
            this.y = y;
        }
        
        public int hashCode()
        {
            return x * y;
        }
        
        @Override
        public boolean equals(Object obj)
        {
            return this.x == ((Position)obj).x
                    && this.y == ((Position)obj).y;
        }
    }

    public int bfs(int[][] matrix, Position p)
    {
        Set<Position> set = new HashSet<>();
        LinkedList<Position> queue = new LinkedList<>();
        Position current = p, tail = p;
        int dist = 0;
        queue.add(p);

        while(!queue.isEmpty())
        {
            current = queue.pollFirst();
            set.add(current);
            if(matrix[current.x][current.y] == 0)
                return dist;
            Position newPosition;
            if(current.x > 0)
            {
                newPosition = new Position(current.x - 1, current.y);
                if (!set.contains(newPosition))
                    queue.add(newPosition);
            }
                
            if(current.x < matrix.length - 1) 
            {
                newPosition = new Position(current.x + 1, current.y);
                if (!set.contains(newPosition))
                    queue.add(newPosition);
            }
            if(current.y > 0)
            {
                newPosition = new Position(current.x, current.y - 1);
                if (!set.contains(newPosition))
                    queue.add(newPosition);
            }
            if(current.y < matrix[current.x].length - 1)
            {
                newPosition = new Position(current.x, current.y + 1);
                if (!set.contains(newPosition))
                    queue.add(newPosition);
            }

            if(current == tail)
            {
                dist++;
                if(!queue.isEmpty())
                    tail = queue.getLast();
            }
        }

        return dist;
    }


    public int[][] updateMatrix(int[][] matrix)
    {
        int[][] res = new int[matrix.length][matrix[0].length];
        
        for(int i = 0; i < matrix.length; i++)
        {
            for(int j = 0; j < matrix[i].length; j++)
            {
                
                if(matrix[i][j] == 0)
                    res[i][j] = 0;
                else
                    res[i][j] = bfs(matrix, new Position(i, j));
            }

        }

        return res;
    }
}