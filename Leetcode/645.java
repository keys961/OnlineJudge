class Solution 
{
    public int[] findErrorNums(int[] nums)
    {
        int[] res = new int[2];
        int[] table = new int[nums.length + 1];
        Arrays.fill(table, 1);
        
        for(int n : nums)
        {
            table[n]--;
            if(table[n] < 0)
                res[0] = n;
        }
        
        for(int i = 1; i < table.length; i++)
            if(table[i] == 1)
            {
                res[1] = i;
                break;
            }
        
        return res;
    }
}