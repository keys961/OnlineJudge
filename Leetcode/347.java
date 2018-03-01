class Solution 
{      
    public List<Integer> topKFrequent(int[] nums, int k)
    {
        List<Integer> result = new ArrayList<>();
        
        HashMap<Integer, Integer> statMap = new HashMap<>();
        for(int n : nums)
        {
            if(!statMap.containsKey(n))
                statMap.put(n, 0);
            statMap.put(n, statMap.get(n) + 1);
        }
        int maxCount = 0;
        for(int n : statMap.keySet())
            maxCount = Math.max(maxCount, statMap.get(n));
        
        List<Integer>[] bucket = new LinkedList[maxCount + 1];
        
        for(int e : statMap.keySet())
        {
            if(bucket[statMap.get(e)] == null)
                bucket[statMap.get(e)] = new LinkedList<>();
            bucket[statMap.get(e)].add(e);
        }
    
        for(int i = bucket.length - 1; i >= 0 && k > 0; i--)
        {
            if(bucket[i] == null)
                continue;
            
            List<Integer> list = bucket[i];
            for(int n : list)
            {
                result.add(n);
                if(--k == 0)
                    break;
            }
        }
        
        return result;
    }
}