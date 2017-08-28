class Solution 
{
    public int maxProfit(int[] prices) 
    {
        if(prices.length == 0)
            return 0;
        int[] diff = new int[prices.length - 1];
        for(int i = 1; i < prices.length; i++)
            diff[i - 1] = prices[i] - prices[i - 1];
        int maxVal = 0, temp = 0;
        for(int i = 0; i < diff.length; i++)
        {
            temp += diff[i];
            if(temp < 0)
                temp = 0;
            if(temp > maxVal)
                maxVal = temp;
        }
        return maxVal;
    }
}