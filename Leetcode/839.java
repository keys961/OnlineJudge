class Solution
{
    private int[] disjointSet;
    
    private void union(int i, int j)
    {
        int r1 = findRoot(i);
        int r2 = findRoot(j);
        
        if(r1 == r2)
            return;
        
        if(disjointSet[r1] < disjointSet[r2])
        {
            disjointSet[r1] +=  disjointSet[r2];
            disjointSet[r2] = r1;
        }
        else
        {
            disjointSet[r2] +=  disjointSet[r1];
            disjointSet[r1] = r2;
        }
    }
    
    private int findRoot(int i)
    {
        if(disjointSet[i] < 0)
            return i;
        
        return findRoot(disjointSet[i]);
    }
    
    public int numSimilarGroups(String[] A) 
    {
        disjointSet = new int[A.length];
        Arrays.fill(disjointSet, -1); // init with -1
        
        for(int i = 0; i < A.length; i++)
        {
            for(int j = i + 1; j < A.length; j++)
            {
                if(isSimilar(A[i], A[j]))
                    union(i, j);
            }
        }
        
        int count = 0;
        for(int i : disjointSet)
            if(i < 0)
                count++;
        return count;
    }
    
    private boolean isSimilar(String a, String b)
    {
        if(a.length() != b.length())
            return false;
        
        boolean status = false;
        int diff = 0;
        int[] map = new int[26];
        
        for(int i = 0; i < a.length(); i++)
        {
            if(++map[a.charAt(i) - 'a'] >= 2)
                status = true;
            
            if(a.charAt(i) != b.charAt(i))
            {
               if(++diff > 2)
                    return false;
            }
        }
        
        if(diff == 2 || (diff == 0 && status))
            return true;
        return false;
    }
}