class Solution 
{
    public boolean hasAlternatingBits(int n)
    {
        int bit = n % 2;
        n >>= 1;
        
        while(n != 0)
        {
            int temp = n % 2;
            if(temp == bit)
                return false;
            bit = temp;
            n >>= 1;
        }
        
        return true;
    }
}