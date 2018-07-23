class Solution 
{
    // Binary Search
    public int minEatingSpeed(int[] piles, int H)
    {
        int max = 0;
        for(int pile : piles)
            max = Math.max(pile, max);
        int low = 1, high = max; // H >= pile.length
        if(H == piles.length)
            return max;
        
        int speed = max;
        while(low < high)
        {
            speed = (low + high) / 2;
            int time = getTime(piles, speed);
            if(time > H)
                low = speed + 1;
            else
                high = speed;
        }
        
        return low;//low must be satisfied..
    }
    
    private int getTime(int[] piles, int speed)
    {
        int res = 0;
        for(int pile : piles)
        {
            res += pile / speed;
            if(pile % speed != 0)
                res += 1;
        }
        
        return res;
    }
}