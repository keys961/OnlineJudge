class Solution
{
//     private boolean helper(int[] gas, int[] cost, int start)
//     {
//         int len = gas.length;
        
//         int rest = 0;
//         for(int i = start; ; i = (i + 1) % len)
//         {
//             rest += gas[i] - cost[i];
//             if(rest < 0)
//                 return false;
            
//             if((i + 1) % len == start)
//                 break;
//         }
        
//         return true;
//     }
    
    public int canCompleteCircuit(int[] gas, int[] cost)
    {
        int remain = 0;
        int total = 0;
        int index = 0;
        
        //like max continuous subarray sum..
        
        for(int i = 0; i < gas.length; i++)
        {
            remain += gas[i] - cost[i]; 
            total += gas[i] - cost[i];
            
            if(remain < 0)
            {
                index = i + 1;
                remain = 0;
            }
          
        }
        
        return total >= 0 ? index : -1;
    }
}