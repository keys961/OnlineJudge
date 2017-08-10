public class Solution
{
    public int reverse(int x)
    {
        long res = 0;
        int sign = 1;
        if(x == 0)
            return 0;
        if(x < 0)
        {
            x = -x;
            sign = -1;
        }
        while(x > 0)
        {
            int digit = x % 10;
            if(res * 10 + digit > Integer.MAX_VALUE)
                return 0;
            res = res * 10 + digit;
            x /= 10;
        }
        return sign * (int)res;
    }
}