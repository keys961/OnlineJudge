public class Solution
{
    public int rangeBitwiseAnd(int m, int n)
    {
        if(m == 0)
            return 0;
        if(m == n)
            return m;
        return rangeBitwiseAnd(m >> 1, n >> 1) << 1;
    }
}