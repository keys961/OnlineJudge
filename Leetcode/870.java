class Solution
{
    private Map<Integer, List<Integer>> indexMap = new HashMap<>(); //index map for B
    
    public int[] advantageCount(int[] A, int[] B)
    {
        int[] result = new int[A.length]; //result
        
        // build map
        for(int i = 0; i < B.length; i++)
        {
            if(!indexMap.containsKey(B[i]))
                indexMap.put(B[i], new ArrayList<>());
            List<Integer> list = indexMap.get(B[i]);
            list.add(i);
        }
        
        // Greedy
        Arrays.sort(A);
        Arrays.sort(B);
        
        int idxA = 0, idxB = 0;
        List<Integer> restNums = new ArrayList<>(100);
        
        while(idxA < A.length)
        {
            if(A[idxA] > B[idxB])
                result[fetchIndex(B[idxB++])] = A[idxA];
            else
                restNums.add(A[idxA]);
            idxA++;
        }
        
        if(!restNums.isEmpty())
        {
            List<Integer> restIndices = fetchIndicesNotFilled();
            for(int i = 0; i < restNums.size(); i++)
                result[restIndices.get(i)] = restNums.get(i);
        }
        
        return result;
    }
    
    private int fetchIndex(int nInB)
    {
        List<Integer> indices = indexMap.get(nInB);
        int res = indices.get(0);
        indices.remove(0);
        if(indices.isEmpty())
            indexMap.remove(nInB);
        
        return res;
    }
    
    private List<Integer> fetchIndicesNotFilled()
    {
        List<Integer> restIndices = new ArrayList<>(100);
        for(int key : indexMap.keySet())
            restIndices.addAll(indexMap.get(key));
        
        return restIndices;
    }
}