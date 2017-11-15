class Solution 
{
    private Map<Integer, List<Integer>> indexMap = new HashMap<>();
    
    private Random r = new Random();
    
    public Solution(int[] nums)
    {
        for(int i = 0; i < nums.length; i++)
        {
            if(!indexMap.containsKey(nums[i]))
                indexMap.put(nums[i], new ArrayList<Integer>());
            List<Integer> list = indexMap.get(nums[i]);
            list.add(i);
            indexMap.put(nums[i], list);
        }
    }
    
    public int pick(int target) 
    {
        List<Integer> list = indexMap.get(target);
        int index = r.nextInt(list.size());
        return list.get(index);
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */