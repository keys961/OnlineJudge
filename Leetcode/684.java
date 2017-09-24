class Solution
{
    int[] disjointSet = new int[2001];
    
    private int find(int id)
    {
        while(disjointSet[id] > 0)
            id = disjointSet[id];
        return id;
    }
    
    private boolean union(int a, int b)
    {
        int rootA = find(a);
        int rootB = find(b);
        if(rootA == rootB)
            return false;
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
        return true;
    }
    
    public int[] findRedundantConnection(int[][] edges)
    {
        int[] res = new int[2];
        Arrays.fill(disjointSet, -1);   
        for(int i = 0; i < edges.length; i++)
        {
            if(!union(edges[i][0], edges[i][1]))
            {
                res[0] = edges[i][0];
                res[1] = edges[i][1];
                break;
            }
        }
        return res;
    }
}