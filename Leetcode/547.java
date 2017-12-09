class Solution
{

    private void setUnion(int[] disjointSet, int a, int b)
    {
        int rootA = findRoot(disjointSet, a);
        int rootB = findRoot(disjointSet, b);
        if(rootA == rootB)
            return;
        
        if(disjointSet[rootA] < disjointSet[rootB])
        {
            disjointSet[rootA] += disjointSet[rootB];
            disjointSet[rootB] = rootA;
        }
        else
        {
            disjointSet[rootB] += disjointSet[rootA];
            disjointSet[rootA] = rootB;
        }
    }
    
    private int findRoot(int[] disjointSet, int a)
    {
        while(disjointSet[a] >= 0)
            a = disjointSet[a];
        return a;
    }
    
    public int findCircleNum(int[][] M)
    {
        if(M.length <= 0)
            return 0;
        int[] disjointSet = new int[M.length];
        Arrays.fill(disjointSet, -1);
        
        for(int i = 0; i < M.length; i++)
            for (int j = i + 1; j < M[i].length; j++)
                if(M[i][j] != 0)
                    setUnion(disjointSet, i, j);
            
        int cnt = 0;
        for(int i : disjointSet)
        {
            if(i < 0)
                cnt++;
        }
        
        return cnt;
    }
}