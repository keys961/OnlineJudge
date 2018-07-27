class Solution
{
    private List<Integer> result = null;
    
    public List<Integer> splitIntoFibonacci(String S) 
    {
        dfs(S, new ArrayList<>());
        if(result == null)
            return new ArrayList<>(1);
        return result;
    }
    
    private void dfs(String S, List<Integer> list)
    {
        if(result != null)
            return;
        
        if(S.length() == 0)
        {
            if(list.size() >= 3)
                result = new ArrayList<>(list);
            return;
        }
        
        for(int i = 1; i <= S.length(); i++)
        {
            Long num = Long.parseLong(S.substring(0, i));
            if(num > Integer.MAX_VALUE)
                break;
            
            if(num != 0 && S.charAt(0) == '0')
                break;
            
            if(list.size() >= 2)
            {
                if(num.intValue() == list.get(list.size() - 1) + list.get(list.size() - 2))
                {
                    list.add(num.intValue());
                    dfs(S.substring(i), list); //dfs
                    list.remove(list.size() - 1);
                }
            }
            else
            {
                list.add(num.intValue());
                dfs(S.substring(i), list); //dfs
                list.remove(list.size() - 1);
            }
        }
        
    }
}