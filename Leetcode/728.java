class Solution
{
    private boolean isSelfDivisible(int n)
    {
        int temp = n;
        while(temp > 0)
        {
            int digit = temp % 10;
            if(digit == 0)
                return false;
            if(n % digit != 0)
                return false;
            temp /= 10;
        }
        return true;
    }
    
    public List<Integer> selfDividingNumbers(int left, int right) 
    {
        List<Integer> list = new ArrayList<>((right - left + 2) >>> 1);
        for(int i = left; i <= right; i++)
        {
            if(isSelfDivisible(i))
                list.add(i);
        }
        
        return list;
    }
}