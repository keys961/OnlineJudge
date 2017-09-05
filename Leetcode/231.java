class Solution 
{
     public boolean isPowerOfTwo(int n) 
    {
        return Integer.bitCount(n) == 1 && n != Integer.MIN_VALUE;
    }
}