class Solution
{
    private int helper(int n)
    {
        int res = 0;
        while(n != 0)
        {
            res += (n % 10) * (n % 10);
            n /= 10;
        }
        return res;
    }

    public boolean isHappy(int n)
    {
        Set<Integer> set = new HashSet<>();
        while(!set.contains(n))
        {
            set.add(n);
            n = helper(n);
            if(n == 1)
                return true;
        }
        return false;
    }
}