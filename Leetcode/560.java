class Solution 
{
    public int subarraySum(int[] nums, int k)
    {
        int count = 0;
        int sum = 0;
        
        HashMap<Integer, Integer> preSumMap = new HashMap<>(); //nums[i, j] = nums[0, j] - nums[0, i]
        
        for(int i = 0; i < nums.length; i++)
        {
            sum += nums[i];
            
            if(sum == k)//full array cond.
                count++;
            
            if(preSumMap.containsKey(sum - k))
                count += preSumMap.get(sum - k);
            
            if(!preSumMap.containsKey(sum))
                preSumMap.put(sum, 1);
            else
                preSumMap.put(sum, preSumMap.get(sum) + 1);
        }
        
        return count;
    }
}