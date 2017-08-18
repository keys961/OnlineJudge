public class Solution
{
    public double myPow(double x, int n)
    {
        if(n == 0)
            return 1;
        if(x == 0)
            return 0;
        if(x > 1 && n == Integer.MIN_VALUE)
            return 0;

        int sign = 1;
        if(x < 0)
        {
            x = -x;
            if(n % 2 != 0)
                sign = -1;
        }
        if(n < 0)
        {
            x = 1 / x;
            n = -n;
        }
        if(n == 1)
            return x * sign;
        if(n % 2 == 0)
            return sign * myPow(x * x, n / 2);
        else
            return sign * x * myPow(x * x, n / 2);
    }
}