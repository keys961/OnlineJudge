public class Solution
{
    public int trailingZeroes(int n)
    {
        // Z =  N/5 + N /(5*5) + N/(5*5*5)....

        int num = 0;

        while(n > 0)
        {
            num += n / 5;
            n = n / 5;
        }

        return num;
    }
}