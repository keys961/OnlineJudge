class Solution
{
    private Map<Integer, Integer> map = new HashMap<>();
    
    {
        map.put(5, 0);
        map.put(10, 0);
        map.put(20, 0);
    }
    
    public boolean lemonadeChange(int[] bills) 
    {
        for(int bill : bills)
        {
            map.put(bill, map.get(bill) + 1);
            switch(bill)
            {
                case 5: break;
                case 10: 
                {
                    if(map.get(5) == 0)
                        return false;
                    map.put(5, map.get(5) - 1);
                    break;
                }
                case 20:
                {
                    if(map.get(5) > 0 && map.get(10) > 0)
                    {
                        map.put(5, map.get(5) - 1);
                        map.put(10, map.get(10) - 1);
                        break;
                    }
                    else if(map.get(5) >= 3)
                    {
                        map.put(5, map.get(5) - 3);
                        break;
                    }
                    return false;
                }
            }
        }
        
        return true;
    }
}