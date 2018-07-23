class Solution 
{
    public String pushDominoes(String dominoes) 
    {
        int[] vals = new int[dominoes.length()];
        
        Set<Integer> leftIndexSet = new HashSet<>();
        Set<Integer> rightIndexSet = new HashSet<>();
        
        int initWeight = 100001;
        
        for(int i = 0; i < dominoes.length(); i++)
        {
            if(dominoes.charAt(i) == 'L')
                leftIndexSet.add(i);
            else if(dominoes.charAt(i) == 'R')
                rightIndexSet.add(i);
        }
        
        for(int i : leftIndexSet)
        {
            int val = -initWeight;
            for(int j = i; j >= 0; j--)
            {
                vals[j] += val;
                val++;
                if(rightIndexSet.contains(j) || (leftIndexSet.contains(j) && j != i))
                    break;
            }
        }
        
        for(int i : rightIndexSet)
        {
            int val = initWeight;
            for(int j = i; j < vals.length; j++)
            {
                vals[j] += val;
                val--;
                if((leftIndexSet.contains(j) || rightIndexSet.contains(j) && j != i))
                    break;
            }
        }
        
        StringBuilder sb = new StringBuilder();
        for(int val : vals)
        {
            if(val < 0)
                sb.append('L');
            else if(val == 0)
                sb.append('.');
            else
                sb.append('R');
        }
        
        return sb.toString();
    }
}