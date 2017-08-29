public class Solution
{
    public int canCompleteCircuit(int[] gas, int[] cost)
    {
        int n = gas.length;
        if(n == 0)
            return -1;

        int start = n - 1;
        int end = 0;
        int sum = gas[start] - cost[start];
        while(start > end)
        {
            if(sum >= 0)
            {
                sum += gas[end] - cost[end];
                end++;
            }
            else
            {
                start--;
                sum += gas[start] - cost[start];
            }
        }
        return sum >= 0 ? start : -1;
    }
}