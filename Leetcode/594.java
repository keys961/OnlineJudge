class Solution 
{
    public int findLHS(int[] nums) 
    {
        if(nums.length == 0)
            return 0;
        TreeMap<Integer, Integer> map = new TreeMap<>();

        for (int n : nums) 
        {
            if (!map.containsKey(n))
                map.put(n, 1);
            else
                map.put(n, map.get(n) + 1);
        }

        int first = map.firstKey();
        int maxCnt = 0;
        int cnt = map.get(first);
        for (int second : map.keySet()) 
        {
            if (second == first)
                continue;
            if (second - first == 1) 
            {
                cnt += map.get(second);
                maxCnt = Math.max(cnt, maxCnt);
            } 
            //else
            cnt = map.get(second);
            first = second;
        }

        return maxCnt;
    }
}