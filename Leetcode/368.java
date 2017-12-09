class Solution
{

    public List<Integer> largestDivisibleSubset(int[] nums)
    {
        Arrays.sort(nums);

        List<Integer> list = new ArrayList<>();
        if(nums.length <= 0)
            return list;
        int[] dp = new int[nums.length];
        int[] cnt = new int[nums.length];
        int maxCount = 0, maxIndex = 0;
        dp[0] = -1;
        cnt[0] = 1;

        

        for(int i = 1; i < nums.length; i++)
        {
            dp[i] = -1; cnt[i] = 1;
            for(int j = 0; j < i; j++)
            {
                if(nums[i] % nums[j] == 0)
                {
                    if(cnt[j] + 1 >= cnt[i])
                    {
                        dp[i] = j;
                        cnt[i] = cnt[j] + 1;
                        if(cnt[i] > maxCount)
                        {
                            maxCount = cnt[i];
                            maxIndex = i;
                        }
                    }
                }
            }
        }

        while(maxIndex != -1)
        {
            list.add(nums[maxIndex]);
            maxIndex = dp[maxIndex];
        }

        return list;
    }
}