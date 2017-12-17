class Solution 
{
    public boolean isPerfectSquare(int num) 
    {
        int left = 1, right = num;
        while(left <= right)
        {
            long mid = (left + right) >>> 1;
            if(mid * mid < num)
                left = (int)mid + 1;
            else if(mid * mid > num)
                right = (int)mid - 1;
            else
                return true;
        }
        
        return false;
    }
}