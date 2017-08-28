public class Solution
{
    public int maxProfit(int[] prices)
    {
        int firstBuy = Integer.MIN_VALUE, firstSell = 0;
        int secondBuy = Integer.MIN_VALUE, secondSell = 0;

        for(int price : prices)
        {
            if(firstBuy < -price)
                firstBuy = - price;
            if(firstSell < firstBuy + price)
                firstSell = firstBuy + price;

            if(secondBuy < firstSell - price)
                secondBuy = firstSell - price;
            if(secondSell < secondBuy + price)
                secondSell = secondBuy + price;
        }

        return secondSell;
    }
}