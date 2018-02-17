class Solution 
{
    private int findRoot(int[] disjointSet, int index)
    {
        if(disjointSet[index] < 0)
            return index;
        return findRoot(disjointSet, disjointSet[index]);
    }
    
    private void union(int[] disjointSet, int index1, int index2)
    {
        int root1 = findRoot(disjointSet, index1);
        int root2 = findRoot(disjointSet, index2);
        
        if(root1 == root2)
            return;
        if(disjointSet[root1] < disjointSet[root2])
        {
            disjointSet[root1] += disjointSet[root2];
            disjointSet[root2] = root1;
        }
        else
        {
            disjointSet[root2] += disjointSet[root1];
            disjointSet[root1] = root2;
        }
    }
    
    public int longestConsecutive(int[] nums) 
    {
        Map<Integer, Integer> indexMap = new HashMap<>();//to support negative..
        int[] disjointSet = new int[nums.length];
        for(int i = 0; i < nums.length; i++)
        {
            indexMap.put(nums[i], i);
        }
        Arrays.fill(disjointSet, -1);
        
        for(int n : nums)
        {
            if(indexMap.containsKey(n - 1))
                union(disjointSet, indexMap.get(n), indexMap.get(n - 1));
            if(indexMap.containsKey(n + 1))
                union(disjointSet, indexMap.get(n), indexMap.get(n + 1));
        }
        int max = 0;
        for(int i = 0; i < disjointSet.length; i++)
        {
            if(-disjointSet[i] > max)
                max = -disjointSet[i];
        }
        return max;
    }
}