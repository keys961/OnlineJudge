class Solution 
{
    private boolean status = false;
    
    public boolean reorderedPowerOf2(int N) 
    {
        List<Integer> digits = new ArrayList<>(10);
        while(N > 0)
        {
            digits.add(N % 10);
            N /= 10;
        }
        boolean[] visited = new boolean[digits.size()];
        helper(digits, visited, 0);
        
        return status;
    }
    
    private void helper(List<Integer> digits, boolean[] visited, int n)
    {
        if(status)
            return;
        
        if(isAllTrue(visited))
        {
            status = checkPowerOf2(n);
            return;
        }
        
        for(int i = 0; i < visited.length; i++)
        {
            if(!visited[i])
            {
                if(!(n == 0 && digits.get(i) == 0))
                {
                    visited[i] = true;
                    helper(digits, visited, n * 10 + digits.get(i));
                    visited[i] = false;
                }
            }
        }
    }
    
    private boolean checkPowerOf2(int number)
    {
        return Integer.bitCount(number) == 1;
    }
    
    private boolean isAllTrue(boolean[] visited)
    {
        for(boolean v : visited)
            if(!v)
                return false;
        return true;
    }
    
}