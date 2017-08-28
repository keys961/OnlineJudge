class Solution
{
    public int maxProfit(int[] prices)
    {
        if(prices.length == 0)
            return 0;
        int[] diff = new int[prices.length - 1];
        for(int i = 1; i < prices.length; i++)
            diff[i - 1] = prices[i] - prices[i - 1];
        int val = 0;
        for(int i = 0; i < diff.length; i++)
        {
            if(diff[i] > 0)
                val += diff[i];
        }
        return val;
    }
}