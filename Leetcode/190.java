public class Solution
{
    public int reverseBits(int n)
    {
        int res = 0;
        for(int i = 0; i < 32; i++)
        {
            int bit = n & 1;
            res += bit;
            n >>>= 1;
            if(i < 31)
                res <<= 1;
        }
        return res;
    }
}